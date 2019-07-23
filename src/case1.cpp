#include <case1.h>
#include <map>
#include <string>
#include <vector>

std::string Case1Test::name() { return "Case 1"; }

float Case1Test::getScheduleValue(float time) {
  if (time <= firstTimeStamp) {
    return schedule.data[firstTimeStamp];
  } else if (schedule.data.find(time) != schedule.data.end()) {
    return schedule.data[time];
  } else {
    auto potentialSelection = schedule.data[firstTimeStamp];
    for (auto & it : schedule.data) {
      if (time >= schedule.data[it.first]) {
        potentialSelection = it.second;
        break;
      }
    }
    return potentialSelection;
  }
}

void Case1Test::fillHourlyData() {
  firstTimeStamp = 1;
  for (int hour = 1; hour <= 8760; hour++) {
    schedule.data[hour] = 2 * hour;
  }
}
