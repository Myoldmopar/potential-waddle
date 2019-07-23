#ifndef BASE_H
#define BASE_H

#include <string>

class BaseScheduleTest {
public:
  virtual std::string name() = 0;
  virtual void fillHourlyData() = 0;
  virtual float getScheduleValue(float currentTime) = 0;
};

#endif // BASE_H
