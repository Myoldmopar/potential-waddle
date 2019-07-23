#ifndef TESTSCHEDULINGSTUFF_BASE_H
#define TESTSCHEDULINGSTUFF_BASE_H

class BaseScheduleTest {
public:
    virtual void setup() = 0;
    virtual void query() = 0;
};

#endif //TESTSCHEDULINGSTUFF_BASE_H
