#include "market.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

namespace Terminal {
    void loadData(const std::string& filename, std::vector<Price>& prices) {
        std::ifstream file(filename);
        Price p;
        while (file >> p) prices.push_back(p);
        file.close();
    }

    void saveData(const std::string& filename, const std::vector<Price>& prices) {
        std::ofstream file(filename);
        for (Price p : prices) file << p << "\n";
        file.close();
    }

    void sortDescending(std::vector<Price>& prices) {
        std::sort(prices.begin(), prices.end(), [](Price a, Price b) { return a > b; });
    }

    void simulateDay(std::vector<Price>& prices, int shares, double balance) {
        std::srand((unsigned)std::time(0));
        Price last = prices.empty() ? START_PRICE : prices.back();
        Price change = (std::rand() % 200 - 100) / 10.0;
        Price next = std::max(1.0, last + change);
        prices.push_back(next);
        if (prices.size() > MAX_DAYS) prices.erase(prices.begin());

        std::cout << "New price: " << next << "\n";
        std::cout << "Your shares (" << shares << "x) are now worth: " << (shares * next) << "\n";
        std::cout << "Total value (shares + balance): " << (shares * next + balance) << "\n";
    }

    void analyze(const std::vector<Price>& prices) {
        if (prices.empty()) {
            std::cout << "No data.\n";
            return;
        }
        Price min = *std::min_element(prices.begin(), prices.end());
        Price max = *std::max_element(prices.begin(), prices.end());
        Price sum = 0;
        for (Price p : prices) sum += p;
        std::cout << "Min: " << min << " Max: " << max << " Avg: " << (sum / prices.size()) << "\n";
    }
}
