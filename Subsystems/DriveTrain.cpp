// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
//
//TODO: Calculate actual Distance Per Pulse on BigBallBot and set in RobotBuilder
//TODO: Add ability to switch between Coast and Break mode on Drive Train Jags
//
#include "DriveTrain.h"
#include "../Robotmap.h"
#include "../Commands/Drive.h"
#include "Math.h"
const float SENSITIVITY = 3;
const float BRAKEMODEVOLTAGE = 8;
const float BRAKEMODERAMP = 9;

DriveTrain::DriveTrain() :
	Subsystem("DriveTrain") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	rightEncoder = RobotMap::driveTrainRightEncoder;
	frontLeftMotor = RobotMap::driveTrainFrontLeftMotor;
	centerLeftMotor = RobotMap::driveTrainCenterLeftMotor;
	rearLeftMotor = RobotMap::driveTrainRearLeftMotor;
	frontRightMotor = RobotMap::driveTrainFrontRightMotor;
	centerRightMotor = RobotMap::driveTrainCenterRightMotor;
	rearRightMotor = RobotMap::driveTrainRearRightMotor;
	leftEncoder = RobotMap::driveTrainLeftEncoder;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Robot::netTable->PutNumber("DriveTrain::Sensitivity", SENSITIVITY); 
}
void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new Drive());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
//
void DriveTrain::Set(float speed) {
	SetLeft(speed);
	SetRight(speed);
}
void DriveTrain::SetLeft(float speed) {
	speed = Delinearize(speed);
	//cap the speed
	speed = speed < -1 ? -1 : speed;
	speed = speed > 1 ? 1 : speed;
	frontLeftMotor->Set(speed);
	centerLeftMotor->Set(speed);
	rearLeftMotor->Set(speed);
}
void DriveTrain::SetRight(float speed) {
	speed = Delinearize(speed);
	speed = speed * -1;	//right side is inverted
	//cap the speed
	speed = speed < -1 ? -1 : speed;
	speed = speed > 1 ? 1 : speed;
	frontRightMotor->Set(speed);
	centerRightMotor->Set(speed);
	rearRightMotor->Set(speed);
}

float DriveTrain::GetFeet() {
	return (leftEncoder->GetDistance() + rightEncoder->GetDistance()) / 2;
}
void DriveTrain::ResetEncoders() {
	leftEncoder->Reset();
	rightEncoder->Reset();
}
double DriveTrain::PIDGet() {
	return GetFeet();
}
void DriveTrain::PIDWrite(float value) {
	Set(value);
}
void DriveTrain::SetBreakMode() {
		frontLeftMotor->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		centerLeftMotor->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		rearLeftMotor->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		frontRightMotor->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		centerRightMotor->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		rearRightMotor->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		
		frontLeftMotor->SetVoltageRampRate(BRAKEMODERAMP);
		centerLeftMotor->SetVoltageRampRate(BRAKEMODERAMP);
		rearLeftMotor->SetVoltageRampRate(BRAKEMODERAMP);
		frontRightMotor->SetVoltageRampRate(BRAKEMODERAMP);
		centerRightMotor->SetVoltageRampRate(BRAKEMODERAMP);
		rearRightMotor->SetVoltageRampRate(BRAKEMODERAMP);
		
		frontLeftMotor->ConfigMaxOutputVoltage(BRAKEMODEVOLTAGE);
		centerLeftMotor->ConfigMaxOutputVoltage(BRAKEMODEVOLTAGE);
		rearLeftMotor->ConfigMaxOutputVoltage(BRAKEMODEVOLTAGE);
		frontRightMotor->ConfigMaxOutputVoltage(BRAKEMODEVOLTAGE);
		centerRightMotor->ConfigMaxOutputVoltage(BRAKEMODEVOLTAGE);
		rearRightMotor->ConfigMaxOutputVoltage(BRAKEMODEVOLTAGE);
		
		frontLeftMotor->EnableControl();
		centerLeftMotor->EnableControl();
		rearLeftMotor->EnableControl();
		frontRightMotor->EnableControl();
		centerRightMotor->EnableControl();
		rearLeftMotor->EnableControl();

}

void DriveTrain::SetCoastMode() {
		frontLeftMotor->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		centerLeftMotor->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		rearLeftMotor->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		frontRightMotor->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		centerRightMotor->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		rearRightMotor->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		
		frontLeftMotor->SetVoltageRampRate(0);
		centerLeftMotor->SetVoltageRampRate(0);
		rearLeftMotor->SetVoltageRampRate(0);
		frontRightMotor->SetVoltageRampRate(0);
		centerRightMotor->SetVoltageRampRate(0);
		rearRightMotor->SetVoltageRampRate(0);
		
		frontLeftMotor->ConfigMaxOutputVoltage(13);
		centerLeftMotor->ConfigMaxOutputVoltage(13);
		rearLeftMotor->ConfigMaxOutputVoltage(13);
		frontRightMotor->ConfigMaxOutputVoltage(13);
		centerRightMotor->ConfigMaxOutputVoltage(13);
		rearRightMotor->ConfigMaxOutputVoltage(13);
		
		frontLeftMotor->EnableControl();
		centerLeftMotor->EnableControl();
		rearLeftMotor->EnableControl();
		frontRightMotor->EnableControl();
		centerRightMotor->EnableControl();
		rearLeftMotor->EnableControl();
}


void DriveTrain::ResetJags() {
	SetCoastMode();
	printf("RESET JAGS \n");
}
float DriveTrain::Delinearize(float x) {
	int sign = 1;
	if (x < 0) {
		sign = -1;
	}
	float _sensitivity = Robot::netTable->GetNumber("DriveTrain::Sensitivity",3);
	return sign * (atan((2 * abs(x) - 1) * (_sensitivity)) / atan(_sensitivity) + 1) / 2;
}
