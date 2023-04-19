/** Main.cpp is the driver code for this program. The goal was to have as few
 * lines of code in this file as possible. Within main.cpp there are only 3
 * lines of code, which create a new object, then using the new object there are
 * 2 function calls, CreateGroceryInventory() to access the input file and
 * output to the new file, then MainMenu() to allow the user to perform tasks
 * using the data from the input file
 *
 * Created By: Rachel Siminski
 * Created: 4/16/2023
**/

#include <iostream>
#include <map>

using namespace std;

#include "Grocery.h"

int main() {

    Grocery obj;
    obj.CreateGroceryInventory();
    obj.MainMenu();

    return 0;
}

//END main.cpp
