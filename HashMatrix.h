#pragma once
#include <iostream>
#include <utility>  // for std::pair
#include <vector>
#include "Cars.h"

using namespace std;

const int LATITUDE_MAX = 14;
const int LONGITUDE_MAX = 37;

class Globe
{
    // truct to represent a node in the graph
struct Node {
  int longitude;  // x coordinate
  int latitude;  // y coordinate
  Car* car;
  Node* next;
};
private:
    vector<vector<Node>>* globe = new vector<vector<Node>>;
public:
    Globe()
    {
        for (int i = 0; i < LATITUDE_MAX; i++) {
            vector<Node> temp;
            for (int j = 0; j < LONGITUDE_MAX; j++) {
                Node* newNode = new Node;
                newNode->longitude = j;
                newNode->latitude = i;
                newNode->car = nullptr;
                newNode->next = nullptr;
                temp.push_back(*newNode);
            }
            globe->push_back(temp);
        }

    }

    void hash (int &longitude, int &latitude) {
        latitude = int(latitude/10)+6;
        longitude = int(longitude/10)+18;
    }

    void insertCar(Car* car) {
        int longitude = car->dealer_longitude;
        int latitude = car->dealer_latitude;
        hash(longitude, latitude);
        Node* newNode = new Node;
        newNode->longitude = longitude;
        newNode->latitude = latitude;
        // cout<<longitude<<endl;
        // cout<<latitude<<endl;
        newNode->car = car;
        newNode->next = nullptr;
        Node* head = &globe->at(latitude).at(longitude);
        //Node* head = globe[latitude][longitude];
        if (head->car == nullptr) {
            head->car = car;
        } else {
            while (head->next != nullptr) {
                head = head->next;
            }
            head->next = newNode;
        }
        // cout<<*head->car<<endl;
    }

    void printByCoordinates(int longitude, int latitude) {
        hash(longitude, latitude);
        Node* head = &globe->at(latitude).at(longitude);
        cout<<*head->car<<endl;
        while (head != nullptr) {
            if (head->car != nullptr) {
                cout << *head->car << endl;
            }
            head = head->next;
        }
    }
    void printRegions() {
        for (int i = 0; i < LATITUDE_MAX; i++) {
            for (int j = 0; j < LONGITUDE_MAX; j++) {
                cout <<"("<< (i-6)*10 <<" , "<< (j-18)*10 << ") - (" <<(i-5)*10  << " - " << (j-17)*10 << ")\t\t";
            cout << endl;
            }
        }
    }

    void printByRegion(int longitude, int latitude, int radius) {
        hash(longitude, latitude);
        int min_longitude = longitude - radius;
        int max_longitude = longitude + radius;
        int min_latitude = latitude - radius;
        int max_latitude = latitude + radius;
        for (int i = min_latitude; i <= max_latitude; i++) {
            for (int j = min_longitude; j <= max_longitude; j++) {
                if (i >= 0 && i < LATITUDE_MAX && j >= 0 && j < LONGITUDE_MAX) {
                    Node* head = &globe->at(i).at(j);
                    while (head != nullptr) {
                        if (head->car != nullptr) {
                            cout << *head->car << endl;
                        }
                        head = head->next;
                    }
                }
            }
        }
    }

    void printRectangularRegion(int longitude1, int latitude1, int longitude2, int latitude2) {
        hash(longitude1, latitude1);
        hash(longitude2, latitude2);
        int min_longitude = min(longitude1, longitude2);
        int max_longitude = max(longitude1, longitude2);
        int min_latitude = min(latitude1, latitude2);
        int max_latitude = max(latitude1, latitude2);
        for (int i = min_latitude; i <= max_latitude; i++) {
            for (int j = min_longitude; j <= max_longitude; j++) {
                if (i >= 0 && i < LATITUDE_MAX && j >= 0 && j < LONGITUDE_MAX) {
                    Node* head = &globe->at(i).at(j);
                    while (head != nullptr) {
                        if (head->car != nullptr) {
                            cout << *head->car << endl;
                        }
                        head = head->next;
                    }
                }
            }
        }
    }
};
