#ifndef TESTSCHEDULINGSTUFF_CASE1_H
#define TESTSCHEDULINGSTUFF_CASE1_H

#include <vector>
#include <map>
#include <base.h>

class Case1Test : public BaseScheduleTest {
    float currentTime;
    struct Schedule {
        std::map<double, double> scheduledData;
    };
    std::vector<Schedule> schedules;
    float inline getScheduleValue(int index);
public:
    void setup() override;
    void query() override;
};

#endif //TESTSCHEDULINGSTUFF_CASE1_H
