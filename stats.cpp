
#include "stats.h"
#include <math.h>
#include <iostream>
#include <algorithm>

Statistics::Stats Statistics::ComputeStatistics(const std::vector<double>& vect) {
    //Implement statistics here

	Stats stat;

	if (vect.size() == 0)
	{
		stat.average = NAN;
		stat.max = NAN;
		stat.min = NAN;
		return stat;
	}
	else
	{
		stat.max = *max_element(vect.begin(), vect.end());
		stat.min = *min_element(vect.begin(), vect.end());

		double sum = 0.0;
		for (const float &i : vect) {
			sum += (double)i;
		}
		stat.average = (float) sum / vect.size();
	}

	return stat;
}

void EmailAlert::Alert()
{
	
}

void LEDAlert::Alert()
{

}

StatsAlerter::StatsAlerter(const float f, std::vector<IAlerter*> v)
{

}

void StatsAlerter::checkAndAlert(const std::vector<double>& vec)
{
	EmailAlert email;
	LEDAlert led;

	for (double a : vec)
	{
		if (a > 10.8)
		{
			email.emailSent = true;
			led.ledGlows = true;
		}
	}
}


