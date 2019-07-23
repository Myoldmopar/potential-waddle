#ifndef BASE_H
#define BASE_H

class BaseScheduleTest {
public:
  virtual void setup() = 0;
  virtual float getScheduleValue(float currentTime) = 0;
};

#endif // BASE_H
