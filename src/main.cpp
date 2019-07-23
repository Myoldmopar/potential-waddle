#include <chrono>
#include <iostream>

#include <base.h>
#include <case1.h>
#include <case2.h>

using namespace std::chrono;

void timeFunctions(BaseScheduleTest *b, std::string const &desc) {
  // build up the schedule data
  auto start1 = high_resolution_clock::now();
  b->setup();
  auto stop1 = high_resolution_clock::now();
  auto duration1 = duration_cast<std::chrono::microseconds>(stop1 - start1);
  std::cout << desc << " Setup Time: " << duration1.count() << " μs\n";
  // exercise the schedule data
  auto start2 = high_resolution_clock::now();
  float currentTime;
  for (int hour = 1; hour <= 8760; hour++) {
    for (int timeStep = 1; timeStep <= 4; timeStep++) {
      currentTime = float(hour) + float(timeStep) / 4.0;
      b->getScheduleValue(currentTime);
    }
  }
  auto stop2 = high_resolution_clock::now();
  auto duration2 = duration_cast<std::chrono::milliseconds>(stop2 - start2);
  std::cout << desc << " Query Time: " << duration2.count() << " ms\n";
}

int main() {
  Case1Test c1;
  timeFunctions(&c1, "Case 1");
  Case2Test c2;
  timeFunctions(&c2, "Case 2");
}
