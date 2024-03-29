#include <algorithm>

#include <case2.h>

std::string Case2Test::name() { return "Case 2 - separate time/value arrays"; }

void Case2Test::fillHourlyData() {
  for (int hour = 1; hour <= 8760; hour++) {
    timestamps.push_back(hour);
    values.push_back(BaseScheduleTest::knownValue(hour));
  }
}

double Case2Test::getScheduleValue(double time) {
  if (time <= timestamps.front()) {
    return values.front();
  } else {
    auto perfectMatch = std::find(timestamps.begin(), timestamps.end(), time);
    if (perfectMatch != timestamps.end()) {
      auto const index = std::distance(timestamps.begin(), perfectMatch);
      return values[index];
    } else {
      auto potentialSelection = values.front();
      for (size_t i = 0; i < timestamps.size(); i++) {
        if (timestamps[i] >= time) {
          potentialSelection = values[i];
          break;
        }
      }
      return potentialSelection;
    }
  }
}
