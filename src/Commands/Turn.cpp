#include "Turn.h"
#include "iostream"
using namespace std;
Turn::Turn(double _setpoint, double kP) : setpoint(_setpoint), pid(new AutoWVPIDController(kP, kI, kD, setpoint, false)) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drive);
	std::cout<<"Turn Constructor Successful" <<std::endl;
}
// Called just before this Command runs the first time
void Turn::Initialize() {
	std::cout<<"Turn Initialize Gyro Reset Successful" <<std::endl;
	drive->gyroReset();
	std::cout<<"Turn Initialize Successful" <<std::endl;
}

// Called repeatedly when this Command is scheduled to run
void Turn::Execute() {

	angle = drive->getAngle();
	cout << "Angle: " << angle;
	double anglePID = -pid->Tick(angle);
	drive->arcadeDrive(0, anglePID, 0.5);
	cout << "   Power Output: " << anglePID;


	// std::cout << -pid->Tick(angle) << std::endl;
	//negative because turning clockwise gyro returns positive
	//but positive input in arcadedrive turns counterclockwise
}

// Make this return true when this Command no longer needs to run execute()
bool Turn::IsFinished(){

	double error = setpoint - drive->getAngle();
	cout << "   Error: " << error<< endl;
	return fabs(error) < 1;
}

// Called once after isFinished returns true
void Turn::End() {
	drive->arcadeDrive(0, 0, 0.5);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Turn::Interrupted() {

}
