#pragma once

#include <string>

class HeatFlow;

class HeatFlowPrinter
{
private:
    HeatFlow &flow;

public:
    HeatFlowPrinter(HeatFlow &flow);
    void pretty_print();
};