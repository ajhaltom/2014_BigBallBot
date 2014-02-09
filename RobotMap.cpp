// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
Encoder* RobotMap::driveTrainRightEncoder = NULL;
CANJaguar* RobotMap::driveTrainFrontLeftMotor = NULL;
CANJaguar* RobotMap::driveTrainCenterLeftMotor = NULL;
CANJaguar* RobotMap::driveTrainRearLeftMotor = NULL;
CANJaguar* RobotMap::driveTrainFrontRightMotor = NULL;
CANJaguar* RobotMap::driveTrainCenterRightMotor = NULL;
CANJaguar* RobotMap::driveTrainRearRightMotor = NULL;
Encoder* RobotMap::driveTrainLeftEncoder = NULL;
DoubleSolenoid* RobotMap::shifterShifterLeft = NULL;
DoubleSolenoid* RobotMap::shifterShifterRight = NULL;
Relay* RobotMap::airCompressorCompressorSpike = NULL;
DoubleSolenoid* RobotMap::pickupArmsLeftShortCylinder = NULL;
DoubleSolenoid* RobotMap::pickupArmsLeftLongCylinder = NULL;
DoubleSolenoid* RobotMap::pickupArmsRightShortCylinder = NULL;
DoubleSolenoid* RobotMap::pickupArmsRightLongCylinder = NULL;
CANJaguar* RobotMap::throwerThrowerMotor = NULL;
AnalogChannel* RobotMap::throwerThrowerEncoder = NULL;
Servo* RobotMap::cameraCameraPanServo = NULL;
Servo* RobotMap::cameraCameraTiltServo = NULL;
CANJaguar* RobotMap::pickupWheelsRightPickupWheel = NULL;
CANJaguar* RobotMap::pickupWheelsLeftPickupWheel = NULL;
AnalogChannel* RobotMap::distanceUltrasonic = NULL;
DigitalOutput* RobotMap::lEDTeamNumber = NULL;
DigitalOutput* RobotMap::lEDTimer = NULL;
DigitalOutput* RobotMap::lEDDistance = NULL;
CANJaguar* RobotMap::clockspringsMotor = NULL;
AnalogChannel* RobotMap::clockspringsPot = NULL;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();
	driveTrainRightEncoder = new Encoder(1, 6, 1, 7, false, Encoder::k4X);
	lw->AddSensor("DriveTrain", "Right Encoder", driveTrainRightEncoder);
	driveTrainRightEncoder->SetDistancePerPulse(1.0);
        driveTrainRightEncoder->SetPIDSourceParameter(Encoder::kRate);
        driveTrainRightEncoder->Start();
	driveTrainFrontLeftMotor = new CANJaguar(2);
	
	
	driveTrainCenterLeftMotor = new CANJaguar(3);
	
	
	driveTrainRearLeftMotor = new CANJaguar(4);
	
	
	driveTrainFrontRightMotor = new CANJaguar(5);
	
	
	driveTrainCenterRightMotor = new CANJaguar(6);
	
	
	driveTrainRearRightMotor = new CANJaguar(7);
	
	
	driveTrainLeftEncoder = new Encoder(1, 4, 1, 5, false, Encoder::k4X);
	lw->AddSensor("DriveTrain", "Left Encoder", driveTrainLeftEncoder);
	driveTrainLeftEncoder->SetDistancePerPulse(1.0);
        driveTrainLeftEncoder->SetPIDSourceParameter(Encoder::kRate);
        driveTrainLeftEncoder->Start();
	shifterShifterLeft = new DoubleSolenoid(1, 1, 2);      
	
	
	shifterShifterRight = new DoubleSolenoid(2, 1, 2);      
	
	
	airCompressorCompressorSpike = new Relay(1, 1);
	lw->AddActuator("AirCompressor", "CompressorSpike", airCompressorCompressorSpike);
	
	pickupArmsLeftShortCylinder = new DoubleSolenoid(1, 3, 4);      
	
	
	pickupArmsLeftLongCylinder = new DoubleSolenoid(1, 5, 6);      
	
	
	pickupArmsRightShortCylinder = new DoubleSolenoid(2, 3, 4);      
	
	
	pickupArmsRightLongCylinder = new DoubleSolenoid(2, 5, 6);      
	
	
	throwerThrowerMotor = new CANJaguar(11);
	
	
	throwerThrowerEncoder = new AnalogChannel(1, 4);
	lw->AddSensor("Thrower", "Thrower Encoder", throwerThrowerEncoder);
	
	cameraCameraPanServo = new Servo(1, 1);
	lw->AddActuator("Camera", "Camera Pan Servo", cameraCameraPanServo);
	
	cameraCameraTiltServo = new Servo(1, 2);
	lw->AddActuator("Camera", "Camera Tilt Servo", cameraCameraTiltServo);
	
	pickupWheelsRightPickupWheel = new CANJaguar(8);
	
	
	pickupWheelsLeftPickupWheel = new CANJaguar(12);
	
	
	distanceUltrasonic = new AnalogChannel(1, 2);
	lw->AddSensor("Distance", "Ultrasonic", distanceUltrasonic);
	
	lEDTeamNumber = new DigitalOutput(1, 1);
	
	
	lEDTimer = new DigitalOutput(1, 2);
	
	
	lEDDistance = new DigitalOutput(1, 3);
	
	
	clockspringsMotor = new CANJaguar(9);
	
	
	clockspringsPot = new AnalogChannel(1, 3);
	lw->AddSensor("Clocksprings", "Pot", clockspringsPot);
	
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// Overwrite CAN Jaguar ID assignments to run code in Frisbee Bot.
	
	driveTrainFrontLeftMotor->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);		// set Jag to "coast" when output = 0.0
	driveTrainCenterLeftMotor->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);		// set Jag to "coast" when output = 0.0
	driveTrainRearLeftMotor->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);		// set Jag to "coast" when output = 0.0
	driveTrainFrontRightMotor->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);		// set Jag to "coast" when output = 0.0
	driveTrainCenterRightMotor->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);		// set Jag to "coast" when output = 0.0
	driveTrainRearRightMotor->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);		// set Jag to "coast" when output = 0.0
	
}
