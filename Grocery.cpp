/** Grocery.cpp
* This file is the bulk of the code for my Grocery Project!
* The aim was to create a file which would be almost self contained.
* Main.cpp will only need to call 2 of the function from Grocery.cpp in
* order to run the entire program. There are detailed descriptions for each
* function below. This file will open and read in the contents of the given
* file, then MainMenu() will be called and this function will call the other
* functions until the user selects option 4 to end the program.
*
* Created By: Rachel Siminski
* Created: 4/16/2023
**/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

#include "Grocery.h"

/** CreateGroceryInventory() will open CS210_Project_Three_Input_File.txt and
 * read the contents into a map. The map will act as an orangized vector and
 * will assign each position will the string item name and the integer count,
 * the count will increment each time a item which already exists in the map is
 * read. The file will then be closed and a new file frequency.dat will be opened
 * and the contents of the GroceryInventory map will be output into the file.
 * The file will then be closed.
**/
void Grocery::CreateGroceryInventory() {
    ifstream inFS;     // Input file stream
    ofstream outFS;     // Output file stream
    string groceryItem;     // Temp storage for each item name as file contents are read
    int i;     // For loop to iterate through the file
    string mapKey;   // Map key to check if the item already exists in the map

    // Input file stream will attempt to open the given file, if unable the program
    // will output an error message letting user know file is not opened
    inFS.open("CS210_Project_Three_Input_File.txt");
    if (!inFS.is_open()) {
        cout << "Could not open file CS210_Project_Three_Input_File.txt." << endl;
    }

    // Now that file is open, the program will automatically iterate through
    // the contents and append each item into the GroceryItems vector
    // CS210_Project_Three_Input_File.txt should contain list of grocery items, else problems
    while (!inFS.eof()) {
        inFS >> groceryItem;

        mapKey = groceryItem;

        // if the item in the file is in the map then increment the Count
        // if the item isn't in the file yet then add it to the end with count 1
        if (GroceryInventory.find(mapKey) != GroceryInventory.end()) {
            GroceryInventory[groceryItem] = GroceryInventory[groceryItem] + 1;
        }
        else {
            GroceryInventory[groceryItem] = 1;
        }

    }

    inFS.close(); // Done with file, so close it

   // Open file
    outFS.open("frequency.dat");

    if (!outFS.is_open()) {
        cout << "Could not open file frequency.dat." << endl;
    }

    // Special for loop outputs each item in the map with the count to the file
    for (const auto& kv : GroceryInventory) {
        outFS << "Item: " << kv.first << ", Count: " << kv.second << endl;
    }

    // Done with file, so close
    outFS.close();
}

/** Borrowed from previous project. This function will be used to create the
 * histogram for the output in option 3. Given size n and char c this function
 * outputs n number of c char. Example: nCharString(5,'&') will output &&&&&
**/
string Grocery::nCharString(size_t t_n, char t_c) {
    int i;   // declare i to implement for loop
    string nChar = "";   // declare and intitialize nChar before loop

    for (i = 0; i < t_n; ++i) {   // for loop to concat char c for n number of times
        nChar = nChar + t_c;
    }
    // return the n character string
    return nChar;   // nChar becomes the full concat string
}

/** SearchForItem() is the first menu option. The user will be prompted to
 * enter the item they want to search for. If this item is in the map then the
 * count will be output and the user will be prompted to search another item.
 * If the input is invalid or not in the map the output will be "This item isn't
 * in stock" and prompt for a new input. If the user wishes to return to the main
 * menu they can enter simply "return"
**/
int Grocery::SearchForItem() {  // Menu option 1
    string itemName;

    cout << endl;
    cout << "Enter the item you wish to search for: ";
    cin >> itemName;

    while (itemName != "return") {
        if (GroceryInventory.find(itemName) != GroceryInventory.end()) {
            cout << GroceryInventory[itemName] << endl;
            cout << "Enter the item you wish to search for: ";
            cin >> itemName;
        }
        else {
            cout << "This item isn't in stock" << endl;
            cout << "Enter the item you wish to search for: ";
            cin >> itemName;
        }
    }
    return GroceryInventory[itemName];
}

/** When the user enters 2 in the main menu this funciton is called.
 * Since the GroceryInventory is initially organized into a map this function
 * only needs to print the map using the same loop as CreateGroceryInventory()
 * which outputs to the file.
**/
void Grocery::PrintListWithCounts() {
    cout << endl;

    for (const auto& kv : GroceryInventory) {
        cout << kv.first << " " << kv.second << endl;
    }

    cout << endl;
}

/** This function is called when the user enters 3 in main menu.
 * PrintListWithHistogram() uses a similar loop to output as PrintListWithCounts()
 * but also uses nCharString() to format the histogram using the counts as size t
**/
void Grocery::PrintListWithHistogram() {
    cout << endl;

    for (const auto& kv : GroceryInventory) {
        cout << kv.first << " " << nCharString(kv.second, '*') << endl;
    }

    cout << endl;
}

/** The MainMenu() is the second and last function to be called in main.cpp.
 * This function will output the menu to the user and when the user inputs their
 * choice then MainMenu() calls the appropriate function for whichever option
 * is picked. When the user enters 4 the program is terminated
**/
void Grocery::MainMenu() {
    int userChoice;


    cout << "   Menu:" << endl;
    cout << "1. Search item" << endl;
    cout << "2. Print list of items with amount" << endl;
    cout << "3. Print list of items histogram" << endl;
    cout << "4. End program" << endl;
    cout << endl;
    cout << endl;
    cout << "Please enter your choice:" << endl;

    cin >> userChoice;

    while (userChoice != 4) {
        switch (userChoice) {
        case 1:
            Grocery::SearchForItem();
            break;
        case 2:
            Grocery::PrintListWithCounts();
            break;
        case 3:
            Grocery::PrintListWithHistogram();
            break;
        case 4:
            cout << "This will end the program" << endl;
            break;
        default:   // This will catch any invalid inputs and prompt the user for 
                   // a new input
            cout << "Please enter one of the menu choices" << endl;
            break;
        }
        cout << "Please enter your choice:" << endl;
        cin >> userChoice;
    }
}

//END Grocery.cpp