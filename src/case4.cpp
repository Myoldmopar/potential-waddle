#include <algorithm>

#include <case4.h>

std::string Case4Test::name() { return "Case 4 - pure lower bound search"; }

void Case4Test::fillHourlyData() {
  for (int hour = 1; hour <= 8760; hour++) {
    timestamps.push_back(hour);
    values.push_back(BaseScheduleTest::knownValue(hour));
  }
}

double Case4Test::getScheduleValue(double time) {
  auto item = std::lower_bound (timestamps.begin(), timestamps.end(), time);
  auto index = item - timestamps.begin();
  return values[index];
}
