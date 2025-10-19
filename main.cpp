#include <iostream>
#include <map>
#include "src/heat_flow.hpp"
#include "src/heat_flow_printer.hpp"

int main()
{
  std::map<int, float> sources_and_sinks;
  sources_and_sinks[0] = 100.0;
  float initial_temperature = 10;
  float number_of_sections = 5;
  float K = 0.1;

  HeatFlow flow(initial_temperature, number_of_sections, K, sources_and_sinks);
  HeatFlowPrinter printer(flow);

  flow.tick();
  printer.pretty_print();

  // Prints out:
  // +------+------+------+------+------+
  // | 100  |  10  |  10  |  10  |  10  |
  // +------+------+------+------+------+

  flow.tick();
  printer.pretty_print();

  // Prints out:
  // +------+------+------+------+------+
  // | 100  |  19  |  10  |  10  |  10  |
  // +------+------+------+------+------+

  flow.tick();
  printer.pretty_print();

  // Prints out:
  // +------+--------+--------+------+------+
  // | 100  |  26.2  |  10.9  |  10  |  10  |
  // +------+--------+--------+------+------+

  return 0;
}
