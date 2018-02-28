#include "Auto_Mid_LSwitch.h"
#include "../CommandBase.h"
#include "Delay.h"
#include <iostream>
//#include "Constants.h"


Auto_Mid_LSwitch::Auto_Mid_LSwitch() {
	AddSequential(new DriveForward(Forward_Mid));
	//AddSequential(new Delay(.5));
	AddSequential(new Turn(-90));
	//AddSequential(new Delay(.5));
	AddSequential(new DriveForward(Cross_MidL));
	//AddSequential(new Delay(.5));
	AddSequential(new Turn(90));
	//AddSequential(new Delay(.5));
	AddSequential(new DriveForward(Score_Mid));
	//AddSequential(new Arm(90,.5));
	//AddSequential(new Conveyor(45,2));
}
