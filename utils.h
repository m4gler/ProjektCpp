#pragma once
#include <vector>
#include "market.h"

namespace Terminal {
    void showMenu();
    void buyShares(std::vector<Price>& prices, double& balance, int& shares);
    void sellShares(std::vector<Price>& prices, double& balance, int& shares);
    void showAccount(double balance, int shares);
}
