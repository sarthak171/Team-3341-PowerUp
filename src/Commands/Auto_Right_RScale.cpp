#include "Auto_Right_RScale.h"
#include "../CommandBase.h"
#include "Delay.h"
#include "MoveLiftToHeight.h"
#include "AutoArmMove.h"
#include "ReleaseCrate.h"
//#include "Constants.h"

Auto_Right_RScale::Auto_Right_RScale() {
	AddSequential(new DriveForward(To_Switch+Mid_Targets+To_Scale));
	AddSequential(new Delay(.5));
	AddSequential(new Turn(-90));
	AddSequential(new Delay(.5));
	AddSequential(new DriveForward(Forward_Scale));

	AddParallel(new MoveLiftToHeight(20));
	AddParallel(new AutoArmMove(100));
	//AddSequential(new ArmPositionPID());
	AddSequential(new ReleaseCrate());
	//AddSequential(new Arm(90));
//	AddSequential(new Conveyor(45,2));
}
