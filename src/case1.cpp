#include <case1.h>
#include <map>
#include <string>
#include <vector>

std::string Case1Test::name() {
  return "Case 1";
}

float Case1Test::getScheduleValue(float currentTime) {
  if (schedule.data.find(currentTime) != schedule.data.end()) {
    return schedule.data[currentTime];
  } else {
    for (int i = 0; i < schedule.data.size(); i++) {
      if (currentTime >= schedule.data[i] &&
          currentTime < schedule.data[i + 1]) {
        return schedule.data[i];
      }
    }
  }
  return -1;
}

void Case1Test::fillHourlyData() {
  for (int hour = 1; hour <= 8760; hour++) {
    schedule.data[hour] = 2 * hour;
  }
}
