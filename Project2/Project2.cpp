/*
 Name:  Stephanie Contino
 Date:  10/18/22
 File name: Project2.cpp
 Description: This program creates a linked list and tests inserting nodes before and after, push back and push front, as well as erasing nodes.
 */
#include <iostream>
#include <string>
#include "List.h"

using namespace std;

int main() {
    // Create List
    List<string> *list = new List<string>();

    // Fill List
    list->push_front("chia");
    list->push_front("poppy");
    list->push_back("sunflower");
    list->push_back("pumpkin");
    cout << *list << endl;

    // Erase second item
    list->erase( list->first()->next ); cout << *list << endl;
    // Erase first item
    list->pop_back();  cout << *list << endl;
    // Erase last item
    list->pop_front(); cout << *list << endl;
    cout << "List has " << list->size() << " item(s)" << endl;

    delete list;
}

// [poppy, chia, sunflower, pumpkin]
// [poppy, sunflower, pumpkin]
// [poppy, sunflower]
// [sunflower]
// List has 1 item(s)
