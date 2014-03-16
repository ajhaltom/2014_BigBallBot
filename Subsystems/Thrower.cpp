// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Thrower.h"
#include "../Robotmap.h"
#include "../Robot.h"
Thrower::Thrower() : Subsystem("Thrower") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	throwerMotor = RobotMap::throwerThrowerMotor;
	throwerLimit = RobotMap::throwerThrowerLimit;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void Thrower::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Thrower::Shoot()
{
	throwerMotor->Set(1);
}
void Thrower::Stop()
{
	throwerMotor->Set(0);
}
bool Thrower::isLimitDown()
{


	return throwerLimit->Get() == 0;
}
void Thrower::ResetJags() {
	throwerMotor->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
	throwerMotor->EnableControl();
	//printf("RESET thrower JAGS \n");
}
