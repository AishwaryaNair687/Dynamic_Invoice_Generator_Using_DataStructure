#ifndef BILL_H
#define BILL_H
#include <iostream>
#include <string.h>
#include "class.h"
using namespace std;
void billing::insertp()
{
    new_node = new node;
    cout << "Here you can create a proper bill of the products sold\n";
    cout << "Please provide the name of the product:";
    cin >> new_node->name;
    cout << "Please provide the Manufacturing date of the product(dd/mm/yy): ";
    cin >> new_node->d >> new_node->m >> new_node->y;
    cout << "Please provide the waranty validity date of the product(dd/mm/yy): ";
    cin >> new_node->wd >> new_node->wm >> new_node->wy;
    cout << "Please provide the price of the product:";
    cin >> new_node->price;
    new_node->ptr = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = new_node;
        rear->ptr = front;
    }
    else
    {
        temp = rear;
        rear = new_node;
        temp->ptr = rear;
        rear->ptr = front;
    }
}
void billing::traversep()
{
    int sum = 0;
    int num = 0;
    if (front == NULL && rear == NULL)
        cout << "No products entered\n";
    else if (front == rear)
    {
        temp = front;
        num++;
        cout << "YOUR BILL" << endl;
        cout << num << ":\n";
        cout << "PRODUCT NAME:" << temp->name << endl;
        cout << "PRODUCT SELLING DATE:" << temp->d << "/" << temp->m << "/" << temp->y << endl;
        cout << "PRODUCT WARANTY LAST TILL:" << temp->wd << "/" << temp->wm << "/" << temp->wy << endl;
        cout << "PRODUCT price:" << temp->price << endl;
        sum += temp->price;
    }
    else
    {
        temp = front;
        cout << "YOUR BILL" << endl;
        while (temp->ptr != front)
        {
            num++;
            cout << num << ":\n";
            cout << "PRODUCT NAME:" << temp->name << endl;
            cout << "PRODUCT SELLING DATE:" << temp->d << "/" << temp->m << "/" << temp->y << endl;
            cout << "PRODUCT WARANTY LAST TILL:" << temp->wd << "/" << temp->wm << "/" << temp->wy << endl;
            cout << "PRODUCT price:" << temp->price << "\n";
            sum += temp->price;
            temp = temp->ptr;
        }
        num++;
        cout << num << ":\n";
        cout << "PRODUCT NAME:" << temp->name << endl;
        cout << "PRODUCT SELLING DATE:" << temp->d << "/" << temp->m << "/" << temp->y << endl;
        cout << "PRODUCT WARANTY LAST TILL:" << temp->wd << "/" << temp->wm << "/" << temp->wy << endl;
        cout << "PRODUCT price:" << temp->price << endl;
        sum += temp->price;
    }
    cout << "Total price of purchase:" << sum << endl;
}

void billing::deletebyposition()
{
    int position;
    if (front == NULL && rear == NULL)
    {
        cout << "No products entered in your list yet\n";
    }
    else if (front == rear)
    {
        free(front);
        front = rear = NULL;
        cout << "Product removed\n";
    }
    else
    {
        cout << "Enter the number of the product you want to remove" << endl;
        cin >> position;
        if (position == 1)
        {
            new_node = front;
            front = new_node->ptr;
            rear->ptr = front;
            free(new_node);
            cout << "Product removed\n";
        }
        else
        {
            temp = front;
            int i = 1;
            while (i < position - 1 && temp->ptr != front)
            {
                temp = temp->ptr;
                i++;
            }
            new_node = temp->ptr;
            temp->ptr = new_node->ptr;
            free(new_node);
            cout << "Product removed" << endl;
            if (temp->ptr == front)
            {
                rear = temp;
            }
        }
    }
}
void billing::deletebyname()
{
    string product;
    if (front == NULL && rear == NULL)
        cout << "No products entered\n";
    else if (front == rear)
    {
        delete front;
        cout << "Product removed\n";
        front = rear = NULL;
    }
    else
    {
        {
            cout << "Enter the name of product you want to remove" << endl;
            cin >> product;
            if (front->name.compare(product) == 0)
            {
                temp = front;
                front = temp->ptr;
                rear->ptr = front;
                free(temp);
                cout << "Product removed\n";
            }
            else
            {
                temp = front;
                while (temp->name.compare(product) != 0 && temp->ptr != front)
                {
                    prev = temp;
                    temp = temp->ptr;
                }
                prev->ptr = temp->ptr;
                free(temp);
                cout << "Product removed" << endl;
                if (prev->ptr == front)
                {
                    rear = prev;
                }
            }
        }
    }
}
#endif