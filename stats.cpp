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
		for (const float& i : vect) {
			sum += (double)i;
		}
		stat.average = (float)sum / vect.size();
	}

	return stat;
}

void EmailAlert::Alert()
{
	emailSent = true;
}

void LEDAlert::Alert()
{
	ledGlows = true;
}

StatsAlerter::StatsAlerter(const float maxTreshold, std::vector<IAlerter*> alert)
{
	this->maxThreshold = maxThreshold;

	for (unsigned int i = 0; i < alert.size(); i++)
	{
		this->alert.push_back(alert[i]);
	}
}

void StatsAlerter::checkAndAlert(const std::vector<double>& vec)
{
	for (double a : vec)
	{
		if (a > maxThreshold)
		{
			for (unsigned int i = 0; i < alert.size(); i++)
			{
				alert[i]->Alert();
			}
		}
	}
}