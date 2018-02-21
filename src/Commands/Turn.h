#ifndef Turn_H
#define Turn_H

#include <Utilities/AutoWVPIDController.h>
#include "../CommandBase.h"

class Turn : public CommandBase {
	public:
	Turn(double _setpoint);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
<<<<<<< HEAD
	double kP = 0.07;
=======
	double kP = 0.025;
>>>>>>> d9d81f6ba9f501402b3d1b10363a303bdf995f3f
	double kI = 0;
	double kD = 0.0;
	double setpoint;
	double angle = 0;
	double speed = 0;
	AutoWVPIDController* pid;
};

#endif  // Turn_H
