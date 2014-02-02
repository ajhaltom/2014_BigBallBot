// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "PickupArms.h"
#include "../Robotmap.h"
#include "../Commands/PickupArmsExtend.h"
#include "../Commands/PickupArmsRetract.h"
#include "../Commands/PickupArmsMidwayLo.h"
#include "../Commands/PickupArmsMidwayHi.h"
PickupArms::PickupArms() : Subsystem("PickupArms") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	leftLongCylinder = RobotMap::pickupArmsLeftLongCylinder;
	rightShortCylinder = RobotMap::pickupArmsRightShortCylinder;
	rigthLongCylinder = RobotMap::pickupArmsRigthLongCylinder;
	leftShortCylinder = RobotMap::pickupArmsLeftShortCylinder;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void PickupArms::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void PickupArms::ArmsExtend()
{
	leftShortCylinder->Set(DoubleSolenoid::kForward);
	leftLongCylinder->Set(DoubleSolenoid::kForward);
	rightShortCylinder->Set(DoubleSolenoid::kForward);
	rigthLongCylinder->Set(DoubleSolenoid::kForward);
}
void PickupArms::ArmsRetract()
{
	leftShortCylinder->Set(DoubleSolenoid::kReverse);
	leftLongCylinder->Set(DoubleSolenoid::kReverse);
	rightShortCylinder->Set(DoubleSolenoid::kReverse);
	rigthLongCylinder->Set(DoubleSolenoid::kReverse);
}
void PickupArms::ArmsMidwayLo()
{
	leftShortCylinder->Set(DoubleSolenoid::kReverse);
	leftLongCylinder->Set(DoubleSolenoid::kReverse);
	rightShortCylinder->Set(DoubleSolenoid::kForward);
	rigthLongCylinder->Set(DoubleSolenoid::kForward);
}
void PickupArms::ArmsMidwayHi()
{
	leftShortCylinder->Set(DoubleSolenoid::kForward);
	leftLongCylinder->Set(DoubleSolenoid::kForward);
	rightShortCylinder->Set(DoubleSolenoid::kReverse);
	rigthLongCylinder->Set(DoubleSolenoid::kReverse);
}
void PickupArms::ArmsOff()
{
	leftShortCylinder->Set(DoubleSolenoid::kOff);
	leftLongCylinder->Set(DoubleSolenoid::kOff);
	rightShortCylinder->Set(DoubleSolenoid::kOff);
	rigthLongCylinder->Set(DoubleSolenoid::kOff);
}
