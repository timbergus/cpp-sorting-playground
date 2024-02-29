#include "sorting.h"

Sorting::Sorting()
{
}

Sorting::~Sorting()
{
}

void Sorting::bubbleSort(std::vector<int> *dataset, bool *reset)
{
  bool isSorted = false;

  while (true)
  {
    if (!isSorted)
    {
      isSorted = true;

      for (int i = 1; i < static_cast<int>(dataset->size()); i++)
      {
        if (dataset->at(i - 1) > dataset->at(i))
        {
          std::swap(dataset->at(i - 1), dataset->at(i));

          isSorted = false;
        }
      }
    }
    else
    {
      *reset = true;
      isSorted = false;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(8));
  }
}
