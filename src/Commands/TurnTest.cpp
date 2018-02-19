/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "TurnTest.h"
#include "Turn.h"
#include "Delay.h"

TurnTest::TurnTest() {
	for(double i = .01; i<=1; i+=.01){
		AddSequential(new Turn(90,i));
		AddSequential(new Delay(3));
	}
}
