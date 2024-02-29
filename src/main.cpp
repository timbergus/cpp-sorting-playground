#include <iostream>
#include <raylib.h>
#include <vector>
#include <thread>
#include <algorithm>
#include <random>

#include "sorting.h"

std::vector<int> dataset;

int main(int, char **)
{
  // Create dataset with 1000 elements.

  int ELEMENTS = 1000;

  for (int i = 1; i < ELEMENTS + 1; i++)
  {
    dataset.push_back(i);
  }

  // Randomize the order of the dataset.

  auto rng = std::default_random_engine{};
  std::shuffle(dataset.begin(), dataset.end(), rng);

  // Launch the sorting algorithm that will sort the dataset every 10ms.

  std::thread sorter{Sorting::bubbleSort, &dataset};

  // Create the screen using the dataset size (1px per sample).

  int SCREEN_WIDTH = ELEMENTS;
  int SCREEN_HEIGHT = ELEMENTS;

  SetConfigFlags(FLAG_MSAA_4X_HINT);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sorting Playground");

  SetTargetFPS(120);

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(LIGHTGRAY);

    DrawFPS(10, 10);

    // Draw a rectangle per sample of the dataset.

    double WIDTH = SCREEN_WIDTH / dataset.size();
    double SCALE = SCREEN_HEIGHT / ELEMENTS;

    for (u_long i = 0; i < dataset.size(); i++)
    {
      int item = dataset.at(i);
      int HEIGHT = item * SCALE;

      DrawRectangle(i * WIDTH, SCREEN_HEIGHT - HEIGHT, WIDTH, HEIGHT, BLUE);
    }

    EndDrawing();
  }

  // If we kill the window, we kill the sorting thread.

  if (WindowShouldClose())
  {
    sorter.detach();
  }

  sorter.join();

  CloseWindow();

  return EXIT_SUCCESS;
}
