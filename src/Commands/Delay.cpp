#include "Delay.h"



Delay::Delay(double timeout) {

	Requires(drive);

	//Initialize();

	timer = timeout;

}



void Delay::Initialize() {
	SetTimeout(timer);

}



void Delay::Execute() {
}



bool Delay::IsFinished() {

	return IsTimedOut();

}



void Delay::End() {

}



void Delay::Interrupted() {

	End();

}
