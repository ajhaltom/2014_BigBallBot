// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "DriveNFeet.h"
DriveNFeet::DriveNFeet(float distance) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	_distance = distance;
	float p = Robot::netTable->GetNumber("DriveNFeet::PID_P", DRIVENFEET_PID_P);
	float i = Robot::netTable->GetNumber("DriveNFeet::PID_I", DRIVENFEET_PID_I);
	float d = Robot::netTable->GetNumber("DriveNFeet::PID_D", DRIVENFEET_PID_D);
	float tolerance = Robot::netTable->GetNumber("DriveNFeet::PID_Tolerance", DRIVENFEET_PID_TOLERANCE);
	controller = new PIDController(p,i,d, Robot::driveTrain, Robot::driveTrain);
	controller->SetTolerance(tolerance);
	Robot::driveTrain->setMotorsInverted(true);
}
// Called just before this Command runs the first time
void DriveNFeet::Initialize() 
{
	Robot::driveTrain->ResetEncoders();
	Robot::driveTrain->Set(0);
	controller->SetSetpoint(_distance);
	controller->Enable();
	SetTimeout(5);
	Robot::driveTrain->SetBreakMode();
}
// Called repeatedly when this Command is scheduled to run
void DriveNFeet::Execute() {
	
}
// Make this return true when this Command no longer needs to run execute()
bool DriveNFeet::IsFinished() {
	return controller->OnTarget() || IsTimedOut();
}
// Called once after isFinished returns true
void DriveNFeet::End() {
	Robot::driveTrain->Set(0);
	controller->Disable();

	Robot::driveTrain->SetCoastMode();
	Robot::driveTrain->setMotorsInverted(true);
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveNFeet::Interrupted() {
	End();
}
