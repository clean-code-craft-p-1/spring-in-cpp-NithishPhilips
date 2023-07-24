#include <vector>

class IAlerter {
	virtual void Alert() = 0;
};

class EmailAlert : public IAlerter {
public:
	bool emailSent;
	void Alert();
};

class LEDAlert : public IAlerter {
public:
	bool ledGlows;
	void Alert();
};

class StatsAlerter {
public:
	StatsAlerter(const float, std::vector<IAlerter*>);

	void checkAndAlert(const std::vector<double>&);
};

namespace Statistics {
    // define the Stats structure here. See the tests to infer its properties

	struct Stats {
	public:
		double average = 0;
		double max = 0;
		double min = 0;

	};

    Stats ComputeStatistics(const std::vector<double>& );

}



