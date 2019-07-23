#ifndef CASE1_H
#define CASE1_H

#include <vector>
#include <map>
#include <base.h>

class Case1Test : public BaseScheduleTest {
    struct Schedule {
        std::map<double, double> scheduledData;
    };
    std::vector<Schedule> schedules;
    float inline getScheduleValue(int, float);
public:
    void setup() override;
    void query(float) override;
};

#endif // CASE1_H
