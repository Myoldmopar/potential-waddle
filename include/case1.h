#ifndef CASE1_H
#define CASE1_H

#include <base.h>
#include <map>
#include <string>
#include <vector>

class Case1Test : public BaseScheduleTest {
  struct Schedule {
    std::map<double, double> data;
  };
  Schedule schedule;

public:
  std::string name() override;
  void fillHourlyData() override;
  float getScheduleValue(float) override;
};

#endif // CASE1_H
