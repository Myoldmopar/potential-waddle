#ifndef CASE2_H
#define CASE2_H

#include <vector>

#include <base.h>

class Case2Test : public BaseScheduleTest {
  std::vector<float> timestamps;
  std::vector<float> values;
public:
  std::string name() override;
  void fillHourlyData() override;
  float getScheduleValue(float) override;
};

#endif // CASE2_H
