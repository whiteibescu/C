#include <SoftPWM.h>

SOFTPWM_DEFINE_CHANNEL(A3);

void setup() {
	SoftPWM.begin(490);
}

void loop()
{
	SoftPWM.set(100);
	delay(2000);
	SoftPWM.set(0);
	delay(2000);
}