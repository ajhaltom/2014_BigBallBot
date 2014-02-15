// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
/**
 *
 *
 * @author ExampleAuthor
 */
class DriveTrain: public Subsystem, public PIDSource, public PIDOutput
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Encoder* rightEncoder;
	CANJaguar* frontLeftMotor;
	CANJaguar* centerLeftMotor;
	CANJaguar* rearLeftMotor;
	CANJaguar* frontRightMotor;
	CANJaguar* centerRightMotor;
	CANJaguar* rearRightMotor;
	Encoder* leftEncoder;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	DriveTrain();
	void InitDefaultCommand();
	void Set(float);
	void SetLeft(float);
	void SetRight(float);
	float GetFeet();
	void ResetEncoders();
	virtual double PIDGet();
	virtual void PIDWrite(float);
	void ResetJags();
	float Delinearize(float);
};
#endif