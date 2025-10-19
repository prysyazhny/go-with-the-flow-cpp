#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>

#include "heat_flow_printer.hpp"
#include "heat_flow.hpp"

HeatFlowPrinter::HeatFlowPrinter(HeatFlow &flow) : flow(flow) {}

void HeatFlowPrinter::pretty_print()
{
   const auto &secs = flow.get_sections();
   size_t n = secs.size();
   const int width = 6;

   std::cout << "+";
   for (size_t i = 0; i < n; ++i)
      std::cout << std::string(width, '-') << "+";
   std::cout << "\n";

   std::cout << "|";
   for (size_t i = 0; i < n; ++i)
   {
      float v = secs[i];
      std::ostringstream oss;
      if (std::fabs(v - std::round(v)) < 1e-6)
         oss << static_cast<long long>(std::llround(v));
      else
         oss << std::fixed << std::setprecision(1) << v;
      std::string s = oss.str();

      int pad = width - static_cast<int>(s.size());
      int left = pad / 2;
      int right = pad - left;

      std::cout << std::string(left, ' ') << s << std::string(right, ' ') << "|";
   }
   std::cout << "\n";

   std::cout << "+";
   for (size_t i = 0; i < n; ++i)
      std::cout << std::string(width, '-') << "+";
   std::cout << "\n";
}