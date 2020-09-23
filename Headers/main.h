 #ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <string.h>
#include "bill.h"
#include"class.h"
using namespace std;
void invoice(){
 billing obj;
    int choice;
    do
    {
        cout << ("\nmenu:\n1.INSERT PRODUCT\n2.DISPLAY BILL\n3.DELETE ANY PRODUCT POSTION\n4.DELETE ANY PRODUCT BY NAME\n5.EXIT\nPlease enter your choice: ");
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.insertp();
            break;
        case 2:
            obj.traversep();
            getchar();
            break;
        case 3:
            obj.deletebyposition();
            break;
        case 4:
            obj.deletebyname();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "wrong choice!";
        }
        cout << "\npress enter to continue!";
    } while (choice != 6);
}
#endif