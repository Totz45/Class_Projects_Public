#include "sort.h"
#include <iostream>
#include <algorithm>
#include <SortingBenchmark.h>
#include <Bridges.h>

using namespace bridges;
using namespace bridges::datastructure;
using namespace bridges::benchmark;

int main () {
  Bridges bridges (3, "", "");

  LineChart plot;
  plot.setTitle("Sort Runtime");
  SortingBenchmark sb(plot);

  sb.linearRange (100, 10000, 20);
  sb.setTimeCap(1.0); //1 seconds

  sb.run("bubble sort", bubbleSort);
  sb.run("insertion sort", insertionSort);
  sb.run("quick sort", quickSort);

  bridges.setDataStructure (&plot);
  bridges.visualize();

  LineChart plot2;
  plot2.setTitle("Sort Runtime");
  SortingBenchmark sb2 (plot2);
  sb2.geometricRange(100, 1000000, 1.5);
  sb2.setTimeCap(3.0); //3 seconds

  sb2.run("bubble sort", bubbleSort);
  sb2.run("insertion sort", insertionSort);

  bridges.setDataStructure(plot2);
  bridges.visualize();

  LineChart plot3;
  plot3.setTitle("Sort Runtime");
  SortingBenchmark sb3 (plot3);
  sb3.geometricRange(100, 1000000, 1.5);
  sb3.setTimeCap(3.0); //3 seconds

  sb3.run("bubble sort", bubbleSort);
  sb3.run("insertion sort", insertionSort);
  sb3.run("quick sort", quickSort);

  bridges.setDataStructure(plot3);
  bridges.visualize();

  return 0;
}