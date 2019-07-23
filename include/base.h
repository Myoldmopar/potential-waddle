#ifndef BASE_H
#define BASE_H

class BaseScheduleTest {
public:
  float currentTime = 0;
  virtual void setup() = 0;
  virtual void query() = 0;
};

#endif // BASE_H
