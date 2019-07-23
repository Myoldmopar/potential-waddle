#ifndef CASE1_H
#define CASE1_H

#include <base.h>
#include <map>
#include <vector>

class Case1Test : public BaseScheduleTest {
  struct Schedule {
    std::map<double, double> scheduledData;
  };
  std::vector<Schedule> schedules;

public:
  void setup() override;
  float getScheduleValue(float) override;
};

#endif // CASE1_H
