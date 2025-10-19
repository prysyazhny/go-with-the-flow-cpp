#pragma once

#include <string>
#include <map>
#include <vector>

class HeatFlow
{
private:
    float initial_temperature;
    int number_of_sections;
    float K;
    std::map<int, float> sources_and_sinks;
    std::vector<float> sections;

public:
    HeatFlow(float initial_temperature, int number_of_sections, float K, std::map<int, float> sources_and_sinks);
    void tick();
    const std::vector<float> &get_sections() const;
};