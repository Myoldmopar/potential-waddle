#ifndef CASE2_H
#define CASE2_H

#include <vector>

#include <base.h>

class Case2Test : public BaseScheduleTest {
  std::vector<double> timestamps;
  std::vector<double> values;

public:
  std::string name() override;
  void fillHourlyData() override;
  double getScheduleValue(double) override;
};

#endif // CASE2_H
