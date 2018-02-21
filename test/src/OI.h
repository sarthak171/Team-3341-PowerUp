#ifndef OI_H
#define OI_H
#include "WPILib.h"

class OI {
private:
	Joystick* leftStick;
	Joystick* rightStick;
	Joystick* liftStick;
	XboxController* driveControl;


	Button* shootCrate;
	Button* getCrate;
	Button* testButton;
	Button* calibrateLift;

public:
	OI();
	Joystick* getLeftStick();
	Joystick* getRightStick();
	Joystick* getLiftStick();
	XboxController* getXboxController();



};

#endif  // OI_H
