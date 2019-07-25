#include <algorithm>

#include <case3.h>

std::string Case3Test::name() { return "Case 3 - separate time/value arrays with moving lower bound"; }

void Case3Test::fillHourlyData() {
  for (int hour = 1; hour <= 8760; hour++) {
    timestamps.push_back(hour);
    values.push_back(BaseScheduleTest::knownValue(hour));
  }
}

double Case3Test::getScheduleValue(double time) {
  if (time <= timestamps.front()) {
    return values.front();
  } else {
    auto perfectMatch = std::find(timestamps.begin(), timestamps.end(), time);
    if (perfectMatch != timestamps.end()) {
      auto const index = std::distance(timestamps.begin(), perfectMatch);
      return values[index];
    } else {
      auto potentialSelection = values.front();
      for (size_t i = lastIndexUsed; i < timestamps.size(); i++) {
        if (timestamps[i] >= time) {
          lastIndexUsed = i;
          potentialSelection = values[i];
          break;
        }
      }
      return potentialSelection;
    }
  }
}
