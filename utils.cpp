#include "utils.h"
#include <iostream>
#include <limits>

namespace Terminal {
    void showMenu() {
        std::cout << "\n=== STOCK TERMINAL ===\n";
        std::cout << "1. Show chart\n";
        std::cout << "2. Analyze prices\n";
        std::cout << "3. Sort descending\n";
        std::cout << "4. Simulate next day\n";
        std::cout << "5. Save to file\n";
        std::cout << "6. Buy shares\n";
        std::cout << "7. Sell shares\n";
        std::cout << "8. Show account status\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
    }

    void buyShares(std::vector<Price>& prices, double& balance, int& shares) {
        if (prices.empty()) {
            std::cout << "No prices available.\n";
            return;
        }

        Price current = prices.back();
        int qty;
        std::cout << "Current price: " << current << "\nHow many shares to buy? ";
        std::cin >> qty;

        double cost = current * qty;
        if (cost > balance) {
            std::cout << "Not enough funds.\n";
            return;
        }

        balance -= cost;
        shares += qty;
        std::cout << "Bought " << qty << " shares for " << cost << "\n";
    }

    void sellShares(std::vector<Price>& prices, double& balance, int& shares) {
        if (prices.empty()) {
            std::cout << "No prices available.\n";
            return;
        }

        Price current = prices.back();
        int qty;
        std::cout << "Current price: " << current << "\nHow many shares to sell? ";
        std::cin >> qty;

        if (qty > shares) {
            std::cout << "Not enough shares.\n";
            return;
        }

        double income = current * qty;
        balance += income;
        shares -= qty;
        std::cout << "Sold " << qty << " shares for " << income << "\n";
    }

    void showAccount(double balance, int shares) {
        std::cout << "Account balance: " << balance << "\n";
        std::cout << "Owned shares: " << shares << "\n";
    }
}
