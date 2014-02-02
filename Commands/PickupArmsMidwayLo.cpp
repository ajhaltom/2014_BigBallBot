// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "PickupArmsMidwayLo.h"
PickupArmsMidwayLo::PickupArmsMidwayLo() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::pickupArms);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void PickupArmsMidwayLo::Initialize() {
	SetTimeout(1);
}
// Called repeatedly when this Command is scheduled to run
void PickupArmsMidwayLo::Execute() {
	Robot::pickupArms->ArmsMidwayLo();
}
// Make this return true when this Command no longer needs to run execute()
bool PickupArmsMidwayLo::IsFinished() {
	return IsTimedOut();
}
// Called once after isFinished returns true
void PickupArmsMidwayLo::End() {
	Robot::pickupArms->ArmsOff();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PickupArmsMidwayLo::Interrupted() {
	End();
}
