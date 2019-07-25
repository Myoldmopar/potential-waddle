#include <algorithm>

#include <case5.h>

std::string Case5Test::name() { return "Case 5 - pure lower bound with moving starting point"; }

void Case5Test::fillHourlyData() {
  for (int hour = 1; hour <= 8760; hour++) {
    timestamps.push_back(hour);
    values.push_back(BaseScheduleTest::knownValue(hour));
  }
}

double Case5Test::getScheduleValue(double time) {
  auto item = std::lower_bound (timestamps.begin() + lastIndexUsed - 1, timestamps.end(), time);
  lastIndexUsed = item - timestamps.begin();
  return values[lastIndexUsed];
}
