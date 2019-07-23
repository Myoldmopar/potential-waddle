#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <base.h>
#include <case1.h>
#include <case2.h>
#include <cassert>

std::vector<float> getQueriedData(BaseScheduleTest *b) {
  std::vector<float> d;
  for (int hour = 1; hour <= 8760; hour++) {
    for (int timeStep = 1; timeStep <= 4; timeStep++) {
      float currentTime = float(hour) + float(timeStep) / 4.0;
      d.push_back(b->getScheduleValue(currentTime));
    }
  }
  return d;
}

std::vector<float> getTimeData() {
  std::vector<float> d;
  for (int hour = 1; hour <= 8760; hour++) {
    for (int timeStep = 1; timeStep <= 4; timeStep++) {
      float currentTime = float(hour) + float(timeStep) / 4.0;
      d.push_back(currentTime);
    }
  }
  return d;
}

std::vector<float> getBaselineData() {
  std::vector<float> d;
  for (int hour = 1; hour <= 8760; hour++) {
    for (int timeStep = 1; timeStep <= 4; timeStep++) {
      float currentTime = float(hour) + float(timeStep) / 4.0;
      d.push_back(BaseScheduleTest::knownValue(currentTime));
    }
  }
  return d;
}

void createComparison() {
  std::vector<std::vector<float>> data;
  std::vector<BaseScheduleTest *> toTest{new Case1Test, new Case2Test};
  data.push_back(getTimeData());
  data.push_back(getBaselineData());
  for (auto b : toTest) {
    b->fillHourlyData();
    data.push_back(getQueriedData(b));
  }
  std::ofstream ofs ("/tmp/data.csv", std::ofstream::out);
  for (int columnIndex = 0; columnIndex < data.size(); columnIndex++) {
    if (columnIndex == 0) {
      ofs << "Time,";
    } else if (columnIndex == 1) {
      ofs << "Baseline,";
    } else {
      ofs << "Case" << (columnIndex - 1) << ",";
    }
  }
  ofs << std::endl;
  for (int rowIndex = 0; rowIndex < data[0].size(); rowIndex++) {
    for (int columnIndex = 0; columnIndex < data.size(); columnIndex++) {
      ofs << data[columnIndex][rowIndex] << ',';
    }
    ofs << std::endl;
  }
}

float timeFunctions(BaseScheduleTest *b) {
  using namespace std::chrono;
  // build up the schedule data
  auto start1 = high_resolution_clock::now();
  b->fillHourlyData();
  auto stop1 = high_resolution_clock::now();
  auto tSetup = duration_cast<microseconds>(stop1 - start1).count();
  std::cout << " " << b->name() << " Setup Time: " << tSetup << " μs\n";
  // exercise the schedule data
  auto start2 = high_resolution_clock::now();
  float currentTime;
  float curValue;
  for (int hour = 1; hour <= 8760; hour++) {
    for (int timeStep = 1; timeStep <= 4; timeStep++) {
      currentTime = float(hour) + float(timeStep) / 4.0;
      curValue = b->getScheduleValue(currentTime);
      assert(curValue > 0); // catch for bad schedule lookups only in debug
    }
  }
  auto stop2 = high_resolution_clock::now();
  auto tQuery = duration_cast<microseconds>(stop2 - start2).count();
  std::cout << " " << b->name() << " Query Time: " << tQuery << " μs\n";
  return (float(tSetup) / 1000000) + (float(tQuery) / 1000000);
}

int main() {
  std::cout << "Creating output value comparison... ";
  createComparison();
  std::cout << "Done, ready for timing\n";
  std::vector<BaseScheduleTest *> toTest{new Case1Test, new Case2Test};
  int const numTestPasses = 3;
  for (auto b : toTest) {
    float timeAggregate = 0.0;
    for (int i = 0; i < numTestPasses; i++) {
      timeAggregate += timeFunctions(b);
    }
    float const avgTime = timeAggregate / numTestPasses;
    std::cout << "Average time for " << b->name() << " = " << avgTime << " s\n";
  }
}
