#include "stats.h"
#include "Alert.h"
#include <stdio.h>

#define NAN 0/0;

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void swap(float* xp, float* yp) 
{ 
    float temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
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
		s.average = NAN;
		s.min = NAN;
		s.max = NAN;
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
        printf("%f \n", lnumset[i]); 

	s.min = lnumset[0];
	s.max = lnumset[setlength-1];
	

	return s;
}
