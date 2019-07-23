#ifndef CASE2_H
#define CASE2_H

#include <base.h>

class Case2Test : public BaseScheduleTest {

public:
  std::string name() override;
  void fillHourlyData() override;
  float getScheduleValue(float) override;
};

#endif // CASE2_H
