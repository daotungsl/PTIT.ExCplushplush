// ConsoleBT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "BT1_Total1ToN.h"
using namespace std;


int main()
{
    int choice;
    cout << "Chon bai tap (1: BT1, 2: BT2): ";
    cin >> choice;

    switch (choice) {
    case 1:
        BT1_Total1ToN();  // Gọi bài tập 1
        break;
    case 2:
        //runBT2();  // Gọi bài tập 2
        break;
    default:
        cout << "Lua chon khong hop le.\n";
        break;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
