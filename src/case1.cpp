#include <case1.h>
#include <map>
#include <vector>

// Worker function for getting a schedule value
float inline Case1Test::getScheduleValue(int index, float currentTime) {
  auto & thisSchedule = schedules[index];
  if (thisSchedule.scheduledData.find(currentTime) != thisSchedule.scheduledData.end()) {
    return thisSchedule.scheduledData[currentTime];
  } else {
    for (int i = 0; i < thisSchedule.scheduledData.size(); i++) {
      if (currentTime >= thisSchedule.scheduledData[i] && currentTime < thisSchedule.scheduledData[i + 1]) {
        return thisSchedule.scheduledData[i];
      }
    }
  }
  exit(1); // shouldn't be able to make it here
}

void Case1Test::setup() {
  schedules.emplace_back();
  for (int hour = 1; hour <= 8760; hour++) {
    schedules[0].scheduledData[hour] = 2*hour;
  }
}

void Case1Test::query(float currentTime) {
  // get a schedule value
  getScheduleValue(0, currentTime);
}
