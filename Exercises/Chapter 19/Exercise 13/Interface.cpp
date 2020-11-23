#include <iostream>
#include "Interface.h"

void ShowMenu()
{
    std::cout << "1 - Add inventory part    \n";
    std::cout << "2 - Remove inventory part \n";
    std::cout << "0 - Stop                  \n";
}

char SelectMenuItem()
{
    char menuItem;
    std::cin >> menuItem;
    return menuItem;
}

Inventory EnterInventory()
{
    std::cout << "Enter serial number: ";
    int serialNum;
    std::cin >> serialNum;

    std::cout << "Enter lot number: ";
    int lotNum;
    std::cin >> lotNum;

    std::cout << "Enter manufact date: ";
    std::string manufactDate;
    std::cin >> manufactDate;

    return Inventory{ serialNum, lotNum, manufactDate };
}