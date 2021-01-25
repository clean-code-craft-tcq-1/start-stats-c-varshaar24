#include "stats.h"
#include "Alert.h"


int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void swap(float* xp, float* yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

computedStats compute_statistics(const float* numberset, int setlength) {

	int min_index=0;

	float sum = 0;
	
	float lnumset[setlength];
	//float * lnumset = &lnumarray;


    computedStats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
	
	if((setlength == 0) || (numberset == 0))
		return s;
	
	for(int a=0;a<setlength;a++)
	{
		lnumset[a] = numberset[a];
	}
	
	for(int k=0;k<setlength-1;k++)
	{
		sum += numberset[k];
	}

	s.average = sum/(float)setlength;

	for(int i=0;i<setlength-1;i++)
	{
		min_index = i;

		for(int j =i+1;j<setlength-1;j++)
		{
			if(lnumset[j]<lnumset[min_index])
			{
				min_index = j;
			}
		}

		swap(&lnumset[min_index], &lnumset[i]); 

	}


	s.min = lnumset[0];
	s.max = lnumset[setlength-1];
	

	return s;
}
