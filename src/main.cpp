#include <chrono>
#include <iostream>

#include <case1.h>
#include <case2.h>
#include <base.h>

void timeFunctions(BaseScheduleTest *b, std::string const& desc) {
  auto start1 = std::chrono::high_resolution_clock::now();
  b->setup();
  auto stop1 = std::chrono::high_resolution_clock::now();
  auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);
  std::cout << desc << " Schedule Setup Time: " << duration1.count() << " microseconds" << std::endl;

  auto start2 = std::chrono::high_resolution_clock::now();
  b->query();
  auto stop2 = std::chrono::high_resolution_clock::now();
  auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(stop2 - start2);
  std::cout << desc << " Schedule Query Time: " << duration2.count() << " milliseconds" << std::endl;
}

int main()
{
  Case1Test c1;
  timeFunctions(&c1, "Case 1");
  Case2Test c2;
  timeFunctions(&c2, "Case 2");
}
