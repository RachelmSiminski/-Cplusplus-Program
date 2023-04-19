/** This is the header file for Grocery.cpp. This file declares the public and
 * private functions and data types. The private member is the map declaration
 * for GroceryInventory. The public members are each of the functions
 *
 * Created By: Rachel Siminski
 * Created: 4/16/2023
**/

#ifndef GROCERY_H
#define GROCERY_H

class Grocery {
public:
    void CreateGroceryInventory();
    string nCharString(size_t t_n, char t_c);
    int SearchForItem();
    void PrintListWithCounts();
    void PrintListWithHistogram();
    void MainMenu();
private:
    std::map<std::string, int> GroceryInventory;
};

#endif

//END Grocery.h