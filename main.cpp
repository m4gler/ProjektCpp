#include <iostream>
#include "market.h"
#include "chart.h"
#include "utils.h"

using namespace Terminal;

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: ./program input.txt output.txt\n";
        return 1;
    }

    std::vector<Price> prices;
    std::string inputFile = argv[1];
    std::string outputFile = argv[2];

    double balance = 10000.0;
    int shares = 0;

    loadData(inputFile, prices);

    int choice;
    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: drawChart(prices); break;
            case 2: analyze(prices); break;
            case 3: sortDescending(prices); break;
            case 4: simulateDay(prices, shares, balance); break;
            case 5: saveData(outputFile, prices); break;
            case 6: buyShares(prices, balance, shares); break;
            case 7: sellShares(prices, balance, shares); break;
            case 8: showAccount(balance, shares); break;
            case 0: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
