#pragma once

#include <vector>
#include <fmt/format.h>
#include <thread>
#include <algorithm>

class Sorting
{
public:
  Sorting();
  ~Sorting();

  static void bubbleSort(std::vector<int> *, bool *);
};
