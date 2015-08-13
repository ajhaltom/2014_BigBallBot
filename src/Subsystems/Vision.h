// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef VISION_H
#define VISION_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Vision/AxisCamera.h"
//Camera constants used for distance calculation
#define Y_IMAGE_RES 240		//Y Image resolution in pixels, should be 120, 240 or 480
#define VIEW_ANGLE 49		//Axis M1013
//#define VIEW_ANGLE 41.7		//Axis 206 camera
//#define VIEW_ANGLE 37.4  //Axis M1011 camera
#define PI 3.141592653
//Score limits used for target identification
#define RECTANGULARITY_LIMIT 40
#define ASPECT_RATIO_LIMIT 55
//Score limits used for hot target determination
#define TAPE_WIDTH_LIMIT 50
#define VERTICAL_SCORE_LIMIT 50
#define LR_SCORE_LIMIT 50
//Minimum area of particles to be considered
#define AREA_MINIMUM 150
//Maximum number of particles to process
#define MAX_PARTICLES 8
class Vision: public Subsystem {
	//Structure to represent the scores for the various tests used for target identification
	struct Scores {
		double rectangularity;
		double aspectRatioVertical;
		double aspectRatioHorizontal;
	};
	
	struct TargetReport {
		int verticalIndex;
		int horizontalIndex;
		bool Hot;
		double totalScore;
		double leftScore;
		double rightScore;
		double tapeWidthScore;
		double verticalScore;
	};
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	bool hot;
	ColorImage *image;
	BinaryImage *thresholdImage;
	BinaryImage *filteredImage;
	AxisCamera *m_camera;
	Scores *scores;
	vector<ParticleAnalysisReport> *reports;
	TargetReport target;
	int verticalTargets[MAX_PARTICLES];
	int horizontalTargets[MAX_PARTICLES];
	int verticalTargetCount, horizontalTargetCount;
	void setupNetTable();
	//Methods from example
	bool scoreCompare(Scores scores, bool vertical);
	bool checkTargetHot(TargetReport target);
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	
	Vision();
	void InitDefaultCommand();
	bool isHot();
	void fetchImage();
	void filterImage();
	void processImage();
};
#endif