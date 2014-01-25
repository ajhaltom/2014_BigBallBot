// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Drive.h"
#include "../360Object.h"
Drive::Drive() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void Drive::Initialize() {
	Robot::driveTrain->SetLeft(0);
	Robot::driveTrain->SetRight(0);	
}
// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
//	float leftSpeed = Robot::oi->getLeftJoystick()->GetY();
//	float rightSpeed = Robot::oi->getRightJoystick()->GetY();
	
	float leftSpeed = Robot::oi->getLeftJoystick()->GetRawAxis(LeftYAxis);		// xBox 360
	float rightSpeed = Robot::oi->getLeftJoystick()->GetRawAxis(RightYAxis);	// xBox 360
	
//	Object360 * xbox = dynamic_cast<Object360*>(Robot::oi->getLeftJoystick());
//	float leftSpeed  = xbox->GetLeftY() ;
//	float rightSpeed = xbox->GetRightY();
	
	Robot::driveTrain->SetLeft(leftSpeed);
	Robot::driveTrain->SetRight(rightSpeed);
	}
// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void Drive::End() {
	Robot::driveTrain->SetLeft(0);
	Robot::driveTrain->SetRight(0);	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {
	End();
}
