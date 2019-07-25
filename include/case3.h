#ifndef CASE3_H
#define CASE3_H

#include <vector>

#include <base.h>

class Case3Test : public BaseScheduleTest {
  std::vector<double> timestamps;
  std::vector<double> values;
  int lastIndexUsed = 0;

public:
  std::string name() override;
  void fillHourlyData() override;
  double getScheduleValue(double) override;
};

#endif // CASE3_H
