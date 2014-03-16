// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef _ROBOT_H
#define _ROBOT_H
#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/AutonomousGroup.h"
#include "Subsystems/AirCompressor.h"
#include "Subsystems/Clocksprings.h"
#include "Subsystems/Distance.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/LED.h"
#include "Subsystems/PickupArms.h"
#include "Subsystems/PickupWheels.h"
#include "Subsystems/Shifter.h"
#include "Subsystems/Thrower.h"
#include "Subsystems/Vision.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "OI.h"
class Robot : public IterativeRobot {
public:
	Command *autonomousCommand;
	static OI *oi;
	LiveWindow *lw;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static DriveTrain* driveTrain;
	static Shifter* shifter;
	static AirCompressor* airCompressor;
	static PickupArms* pickupArms;
	static Thrower* thrower;
	static PickupWheels* pickupWheels;
	static Distance* distance;
	static LED* lED;
	static Clocksprings* clocksprings;
	static Vision* vision;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
	InternalButton* dpadHigh;
	InternalButton* dpadLow;
	InternalButton* dpadHigh2;
	InternalButton* dpadLow2;
	
	
	static NetworkTable* netTable;
};
#endif
