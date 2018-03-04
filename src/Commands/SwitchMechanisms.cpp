/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "SwitchMechanisms.h"
#include "MoveLiftToMinHeight.h"
#include "MoveLiftToHeight.h"
#include "ArmPositionPID.h"
#include "AutoArmMove.h"
#include "ArmMin.h"
#include <Commands/CommandGroup.h>

SwitchMechanisms::SwitchMechanisms() {

	AddParallel(new ArmMin());
	AddSequential(new MoveLiftToMinHeight());

	AddSequential(new AutoArmMove(100));
	AddParallel(new MoveLiftToHeight(10));
	AddSequential(new AutoArmMove(250));

	AddSequential(new ArmPositionPID());
}
