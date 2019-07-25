#ifndef CASE4_H
#define CASE4_H

#include <vector>

#include <base.h>

class Case4Test : public BaseScheduleTest {
  std::vector<double> timestamps;
  std::vector<double> values;

public:
  std::string name() override;
  void fillHourlyData() override;
  double getScheduleValue(double) override;
};

#endif // CASE4_H
