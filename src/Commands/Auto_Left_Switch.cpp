#include <Commands/Auto_Left_Switch.h>
#include <iostream>
#include "Delay.h"
#include "../CommandBase.h"
#include "MoveLiftToHeight.h"
#include "MoveLiftToMinHeight.h"
#include "AutoArmMove.h"
#include "ArmMin.h"
#include "ReleaseCrate.h"
//#include "Constants.h"

Auto_Left_Switch::Auto_Left_Switch() {
	AddParallel(new MoveLiftToMinHeight());
	AddParallel(new ArmMin());
	AddSequential(new DriveForward(To_Switch));
	AddSequential(new Delay(.5));
	AddSequential(new Turn(90));
	AddSequential(new Delay(.5));
	AddSequential(new DriveForward(Forward_Switch));
	//AddSequential(new Arm(90,.5));
	//AddSequential(new Conveyor(45,2));
	AddSequential(new AutoArmMove(100));
	//AddSequential(new ArmPositionPID());
	AddSequential(new ReleaseCrate());
}
