// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/CompressorRun.h"
#include "Commands/Drive.h"
#include "Commands/ShifterHigh.h"
#include "Commands/ShifterLow.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	rightJoystick = new Joystick(2);
	
	shiftLowButton = new JoystickButton(rightJoystick, 1);
	shiftLowButton->WhenPressed(new ShifterLow());
	leftJoystick = new Joystick(1);
	
	shiftHighButton = new JoystickButton(leftJoystick, 1);
	shiftHighButton->WhenPressed(new ShifterHigh());
     
        // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
	SmartDashboard::PutData("Drive", new Drive());
	SmartDashboard::PutData("ShifterHigh", new ShifterHigh());
	SmartDashboard::PutData("ShifterLow", new ShifterLow());
	SmartDashboard::PutData("CompressorRun", new CompressorRun());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
Joystick* OI::getRightJoystick() {
	return rightJoystick;
}
Joystick* OI::getLeftJoystick() {
	return leftJoystick;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
