#include "stats.h"
#include <stdio.h>
#include <math.h>

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void swap(float* xp, float* yp) 
{ 
    float temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void emailAlerter()
{
	emailAlertCallCount++;
}

void ledAlerter()
{
	ledAlertCallCount++;
}

computedStats compute_statistics(const float* numberset, int setlength) {

	int min_index=0;
	int i=0;
	int j=0;

	float sum = 0;
	
	float lnumset[setlength];
	//float * lnumset = &lnumarray;


    computedStats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
	
	if((setlength == 0) || (numberset == 0))
	{
		s.average = isnanf(s.average/s.min);
		s.min = isnanf(s.average/s.min);
		s.max = isnan(s.average/s.max);
		return s;
	}
		
	
	for(int a=0;a<setlength;a++)
	{
		lnumset[a] = numberset[a];
		
		sum += numberset[a];
	}

	s.average = sum/(float)setlength;

	for(i=0;i<setlength-1;i++)
	{
		min_index = i;

		for(j =i+1;j<setlength;j++)
		{
			if(lnumset[j]<lnumset[min_index])
			{
				min_index = j;
				
			}
		}

		swap(&lnumset[min_index], &lnumset[i]); 
		
	}
	
	  
    for (i = 0; i < setlength; i++) 
    {
	printf("%f \n", lnumset[i]); 
    }
       

	s.min = lnumset[0];
	s.max = lnumset[setlength-1];
	

	return s;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], computedStats lcomputedStats)
{

	if(lcomputedStats.max > maxThreshold)
	{
		//if(alerters[0] != '\0'}
		alerters[0]();
		//if(alerters[1] != '\0'}
		alerters[1]();
	}
}
