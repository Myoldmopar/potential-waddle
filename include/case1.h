#ifndef CASE1_H
#define CASE1_H

#include <map>
#include <string>
#include <vector>

#include <base.h>

class Case1Test : public BaseScheduleTest {
  struct Schedule {
    std::map<double, double> data; // note std::map is ordered
  };
  Schedule schedule;
  double firstTimeStamp = 0;

public:
  std::string name() override;
  void fillHourlyData() override;
  double getScheduleValue(double) override;
};

#endif // CASE1_H
