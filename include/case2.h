#ifndef CASE2_H
#define CASE2_H

#include <base.h>

class Case2Test : public BaseScheduleTest {

public:
  void setup() override;
  float getScheduleValue(float) override;
};

#endif // CASE2_H
