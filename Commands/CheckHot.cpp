// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.


#include "CheckHot.h"
#include "Vision/AxisCamera.h"

int whileStatementCount = 0;
CheckHot::CheckHot()
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::vision);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void CheckHot::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void CheckHot::Execute() {
//	if (whileStatementCount%20 == 0 || whileStatementCount == 0)
//	{
//		printf("ENTERING EXECUTE for the %ith time\n", whileStatementCount);
//	}
//	whileStatementCount++;
	Scores *scores;
	TargetReport target;
	int verticalTargets[MAX_PARTICLES];
	int horizontalTargets[MAX_PARTICLES];
	int verticalTargetCount, horizontalTargetCount;
	Threshold threshold(0, 360, 0, 100, 0, 100);	//HSV threshold criteria, ranges are in that order ie. Hue is 60-100
	ParticleFilterCriteria2 criteria[] = {
			{IMAQ_MT_AREA, AREA_MINIMUM, 65535, false, false}
	};												//Particle filter criteria, used to filter out small particles
	// AxisCamera &camera = AxisCamera::GetInstance();	//To use the Axis camera uncomment this line
	
	/**
	 * Do the image capture with the camera and apply the algorithm described above. This
	 * sample will either get images from the camera or from an image file stored in the top
	 * level directory in the flash memory on the cRIO. The file name in this case is "testImage.jpg"
	 */
	ColorImage *image;
//	image = new RGBImage("/testImage.jpg");		// get the sample image from the cRIO flash
	AxisCamera &camera = AxisCamera::GetInstance("10.26.19.11");//.GetImage(image);
	if(camera.IsFreshImage())
	{
		image = camera.GetImage();				//To get the images from the camera comment the line above and uncomment this one
	
		image->Write("/testImage2.bmp");
	}
	return;
	//	BinaryImage *testImage = image->ThresholdRGB(0,255,0,255,0,255);
//	testImage->Write("/rgbFiltered.bmp");
	BinaryImage *testImage = image->ThresholdHSL(80,120,0,255,0,255);
	testImage->Write("/hslFiltered.bmp");
	BinaryImage *thresholdImage = image->ThresholdHSV(threshold);	// get just the green target pixels
	thresholdImage->Write("/threshold.bmp");
	BinaryImage *filteredImage = thresholdImage->ParticleFilter(criteria, 1);	//Remove small particles
	filteredImage->Write("Filtered.bmp");

	vector<ParticleAnalysisReport> *reports = filteredImage->GetOrderedParticleAnalysisReports();  //get a particle analysis report for each particle

	verticalTargetCount = horizontalTargetCount = 0;
	//Iterate through each particle, scoring it and determining whether it is a target or not
	
	printf("Report Size is %i\n", reports->size());
	
	if(reports->size() > 0)
	{
		printf("Report\n");
		scores = new Scores[reports->size()];
		for (unsigned int i = 0; i < MAX_PARTICLES && i < reports->size(); i++) {
			ParticleAnalysisReport *report = &(reports->at(i));
			
			//Score each particle on rectangularity and aspect ratio
			scores[i].rectangularity = scoreRectangularity(report);
			scores[i].aspectRatioVertical = scoreAspectRatio(filteredImage, report, true);
			scores[i].aspectRatioHorizontal = scoreAspectRatio(filteredImage, report, false);			
			
			//Check if the particle is a horizontal target, if not, check if it's a vertical target
			if(scoreCompare(scores[i], false))
			{
				printf("particle: %d  is a Horizontal Target centerX: %d  centerY: %d \n", i, report->center_mass_x, report->center_mass_y);
				horizontalTargets[horizontalTargetCount++] = i; //Add particle to target array and increment count
			} else if (scoreCompare(scores[i], true)) {
				printf("particle: %d  is a Vertical Target centerX: %d  centerY: %d \n", i, report->center_mass_x, report->center_mass_y);
				verticalTargets[verticalTargetCount++] = i;  //Add particle to target array and increment count
			} else {
				printf("particle: %d  is not a Target centerX: %d  centerY: %d \n", i, report->center_mass_x, report->center_mass_y);
			}
			printf("Scores rect: %f  ARvert: %f \n", scores[i].rectangularity, scores[i].aspectRatioVertical);
			printf("ARhoriz: %f  \n", scores[i].aspectRatioHorizontal);	
		}

		//Zero out scores and set verticalIndex to first target in case there are no horizontal targets
		target.totalScore = target.leftScore = target.rightScore = target.tapeWidthScore = target.verticalScore = 0;
		target.verticalIndex = verticalTargets[0];
		for (int i = 0; i < verticalTargetCount; i++)
		{
			ParticleAnalysisReport *verticalReport = &(reports->at(verticalTargets[i]));
			for (int j = 0; j < horizontalTargetCount; j++)
			{
				ParticleAnalysisReport *horizontalReport = &(reports->at(horizontalTargets[j]));
				double horizWidth, horizHeight, vertWidth, leftScore, rightScore, tapeWidthScore, verticalScore, total;

				//Measure equivalent rectangle sides for use in score calculation
				imaqMeasureParticle(filteredImage->GetImaqImage(), horizontalReport->particleIndex, 0, IMAQ_MT_EQUIVALENT_RECT_LONG_SIDE, &horizWidth);
				imaqMeasureParticle(filteredImage->GetImaqImage(), verticalReport->particleIndex, 0, IMAQ_MT_EQUIVALENT_RECT_SHORT_SIDE, &vertWidth);
				imaqMeasureParticle(filteredImage->GetImaqImage(), horizontalReport->particleIndex, 0, IMAQ_MT_EQUIVALENT_RECT_SHORT_SIDE, &horizHeight);
				
				//Determine if the horizontal target is in the expected location to the left of the vertical target
				leftScore = ratioToScore(1.2*(verticalReport->boundingRect.left - horizontalReport->center_mass_x)/horizWidth);
				//Determine if the horizontal target is in the expected location to the right of the  vertical target
				rightScore = ratioToScore(1.2*(horizontalReport->center_mass_x - verticalReport->boundingRect.left - verticalReport->boundingRect.width)/horizWidth);
				//Determine if the width of the tape on the two targets appears to be the same
				tapeWidthScore = ratioToScore(vertWidth/horizHeight);
				//Determine if the vertical location of the horizontal target appears to be correct
				verticalScore = ratioToScore(1-(verticalReport->boundingRect.top - horizontalReport->center_mass_y)/(4*horizHeight));
				total = leftScore > rightScore ? leftScore:rightScore;
				total += tapeWidthScore + verticalScore;
				
				//If the target is the best detected so far store the information about it
				if(total > target.totalScore)
				{
					target.horizontalIndex = horizontalTargets[j];
					target.verticalIndex = verticalTargets[i];
					target.totalScore = total;
					target.leftScore = leftScore;
					target.rightScore = rightScore;
					target.tapeWidthScore = tapeWidthScore;
					target.verticalScore = verticalScore;
				}
			}
			//Determine if the best target is a Hot target
			target.Hot = hotOrNot(target);
		}
		
		if(verticalTargetCount > 0)
		{
			//Information about the target is contained in the "target" structure
			//To get measurement information such as sizes or locations use the
			//horizontal or vertical index to get the particle report as shown below
			ParticleAnalysisReport *distanceReport = &(reports->at(target.verticalIndex));
			double distance = computeDistance(filteredImage, distanceReport);
			if(target.Hot)
			{
				printf("Hot target located \n");
				printf("Distance: %f \n", distance);
			} else {
				printf("No hot target present \n");
				printf("Distance: %f \n", distance);
			}
		}
	}

	// be sure to delete images after using them
	delete filteredImage;
	delete thresholdImage;
	delete image;
	
	//delete allocated reports and Scores objects also
	delete scores;
	delete reports;
}

// Make this return true when this Command no longer needs to run execute()
bool CheckHot::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CheckHot::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CheckHot::Interrupted() {
	End();
}
