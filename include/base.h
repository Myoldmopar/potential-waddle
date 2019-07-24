#ifndef BASE_H
#define BASE_H

#include <string>

class BaseScheduleTest {
public:
  virtual std::string name() = 0;
  virtual void fillHourlyData() = 0;
  virtual double getScheduleValue(double currentTime) = 0;
  static double knownValue(double timeHour) { return 2 * timeHour; }
};

#endif // BASE_H
