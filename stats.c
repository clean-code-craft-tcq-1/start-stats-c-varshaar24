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

Stats compute_statistics(const float* numberset, int setlength) {

	int min_index;

	float sum = 0;

    Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;

	for(int i=0;i<setlength-1;i++)
	{
		min_index = i;

		for(int j =i+1;j<setlength;j++)
		{
			if(numberset[j]<numberset[min_index]
			{
				min_index = j;
			}
		}

		swap(numberset[min_idx], numberset[i]); 

	}

	for(int k=0;k<setlength-1;k++)
	{
		sum += numberset[k];
	}

	s.average = sum/setlength;
	s.min = numberset[0];
	s.max = numberset[setlength-1];
	

	return s;
}
