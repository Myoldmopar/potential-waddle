#include <case1.h>
#include <map>
#include <vector>

// Worker function for getting a schedule value
float Case1Test::getScheduleValue(float currentTime) {
  int const scheduleIndex = 0;
  auto &sch = schedules[scheduleIndex];
  if (sch.scheduledData.find(currentTime) != sch.scheduledData.end()) {
    return sch.scheduledData[currentTime];
  } else {
    for (int i = 0; i < sch.scheduledData.size(); i++) {
      if (currentTime >= sch.scheduledData[i] &&
          currentTime < sch.scheduledData[i + 1]) {
        return sch.scheduledData[i];
      }
    }
  }
  return -1;
}

void Case1Test::setup() {
  schedules.emplace_back();
  for (int hour = 1; hour <= 8760; hour++) {
    schedules[0].scheduledData[hour] = 2 * hour;
  }
}
