#include "chart.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

namespace Terminal {
    void drawChart(const std::vector<Price>& prices) {
        if (prices.empty()) {
            std::cout << "No data to draw.\n";
            return;
        }

        Price max = *std::max_element(prices.begin(), prices.end());
        for (int row = 10; row >= 1; --row) {
            for (Price p : prices) {
                if ((p / max) * 10 >= row) std::cout << "* ";

                else std::cout << "  ";
            }
            std::cout << "\n";
        }
    }
}
