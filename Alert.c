
#include "alert.h"

alerter_funcptr emailAlerter()
{
	emailAlertCallCount++;
}

alerter_funcptr ledAlerter()
{
	ledAlertCallCount++;
}



void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{

	if(computedStats.max > maxThreshold)
	{
		if(alerters[0] != '\0'}
		alerters[0];
		if(alerters[1] != '\0'}
		alerters[1];
	}
}
