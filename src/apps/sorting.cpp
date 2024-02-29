#include "sorting.h"

Sorting::Sorting()
{
}

Sorting::~Sorting()
{
}

void Sorting::bubbleSort(std::vector<int> *dataset)
{
  bool isBeingSorted = true;

  while (isBeingSorted)
  {
    isBeingSorted = false;

    for (int i = 1; i < static_cast<int>(dataset->size()); i++)
    {
      if (dataset->at(i - 1) > dataset->at(i))
      {
        std::swap(dataset->at(i - 1), dataset->at(i));

        isBeingSorted = true;
      }
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}
