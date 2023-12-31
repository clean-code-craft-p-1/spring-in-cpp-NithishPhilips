#include "stats.h"
#include <cmath>
#include "gtest/gtest.h"

TEST(Statistics, ReportsAverageMinMax) {
	Statistics::Stats computedStats = Statistics::ComputeStatistics({ 1.5, 8.9, 3.2, 4.5 });
	float epsilon = 0.001;
	EXPECT_LT(std::abs(computedStats.average - 4.525), epsilon);
	EXPECT_LT(std::abs(computedStats.max - 8.9), epsilon);
	EXPECT_LT(std::abs(computedStats.min - 1.5), epsilon);
}

TEST(Statistics, AverageNaNForEmpty) {
	auto computedStats = Statistics::ComputeStatistics({});
	//All fields of computedStats (average, max, min) must be
	//NAN (not-a-number), as defined in math.h
	ASSERT_EQ(std::isnan(computedStats.average), std::isnan(NAN));
	ASSERT_EQ(std::isnan(computedStats.max), std::isnan(NAN));
	ASSERT_EQ(std::isnan(computedStats.min), std::isnan(NAN));
	//Design the REQUIRE statement here.
	//Use http://www.cplusplus.com/reference/cmath/isnan/
}

TEST(Alert, AlertsWhenMaxExceeds) {
	EmailAlert emailAlert;
	LEDAlert ledAlert;
	std::vector<IAlerter*> alerters = { &emailAlert, &ledAlert };
	
	const float maxThreshold = 10.2;
	StatsAlerter statsAlerter(maxThreshold, alerters);
	statsAlerter.checkAndAlert({ 99.8, 34.2, 4.5, 6.7 });
	
	EXPECT_TRUE(emailAlert.emailSent);
	EXPECT_TRUE(ledAlert.ledGlows);
}

