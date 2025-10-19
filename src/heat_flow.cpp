#include <string>
#include <iostream>
#include <cmath>

#include "heat_flow.hpp"

HeatFlow::HeatFlow(float initial_temperature, int number_of_sections, float K, std::map<int, float> sources_and_sinks)
    : initial_temperature(initial_temperature),
      number_of_sections(number_of_sections),
      K(K),
      sources_and_sinks(sources_and_sinks)
{
  sections.assign(this->number_of_sections, this->initial_temperature);
}

void HeatFlow::tick()
{
  if (sections.empty())
    return;

  std::vector<float> next(sections.size());

  for (int i = 0; i < number_of_sections; ++i)
  {
    float cur = sections[i];
    float delta = 0.0f;

    if (number_of_sections == 1)
    {
      delta = 0.0f;
    }
    else if (i == 0)
    {
      float right = sections[i + 1];
      delta = K * (right - cur);
    }
    else if (i == number_of_sections - 1)
    {
      float left = sections[i - 1];
      delta = K * (left - cur);
    }
    else
    {
      float left = sections[i - 1];
      float right = sections[i + 1];
      delta = K * (left + right - 2.0f * cur);
    }

    next[i] = cur + delta;
  }

  for (const auto &p : sources_and_sinks)
  {
    int idx = p.first;
    if (idx >= 0 && idx < (int)next.size())
      next[idx] = p.second;
  }

  sections.swap(next);
}

const std::vector<float> &HeatFlow::get_sections() const
{
  return sections;
}