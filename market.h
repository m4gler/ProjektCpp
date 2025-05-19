#pragma once
#include <vector>
#include <string>

#define MAX_DAYS 60
#define START_PRICE 100.0
typedef double Price;

namespace Terminal {
    void loadData(const std::string& filename, std::vector<Price>& prices);
    void saveData(const std::string& filename, const std::vector<Price>& prices);
    void sortDescending(std::vector<Price>& prices);
    void simulateDay(std::vector<Price>& prices, int shares, double balance);
    void analyze(const std::vector<Price>& prices);
}
