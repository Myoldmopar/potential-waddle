#ifndef CASE5_H
#define CASE5_H

#include <vector>

#include <base.h>

class Case5Test : public BaseScheduleTest {
  std::vector<double> timestamps;
  std::vector<double> values;
  int lastIndexUsed = 0;

public:
  std::string name() override;
  void fillHourlyData() override;
  double getScheduleValue(double) override;
};

#endif // CASE5_H
