#pragma once
#include <iostream>
#include "parser.h"
#include "Cars.h"
#include "CarAVL.h"
#include "CarTAVL.h"
#include "HashTable.h"
#include "HashMatrix.h"

using namespace std;

// AVL trees for each of the three attributes
CarAVL <Car> * carsByMakeAndModel = new CarAVL<Car>();
CarAVL <Date> * carsByDate = new CarAVL<Date>();
CarAVL <string> * carsByMake = new CarAVL<string>();
CarTAVL <string> * carsByCountry = new CarTAVL<string>();

// Hash table for the country attribute
HashTable <int>* carsByAge = new HashTable<int>(75, "age");
HashTable <float>* carsByPrice = new HashTable<float>(150, "price");

// Hash matrix for the location attribute
Globe * globe = new Globe();

void parsingData()
{
    parseData(carsByMake, carsByDate, carsByMakeAndModel, carsByCountry, carsByPrice, carsByAge, globe);
}

void sortedPrint(string key, bool ascending)
{
    cout << "Cars sorted by " << key << endl;
    if (key == "make")
    {
        if (ascending)
            carsByMake->printInOrder();
        else
            carsByMake->printInReverseOrder();
    }
    else if (key == "date")
    {
        if (ascending)
            carsByDate->printInOrder();
        else
            carsByDate->printInReverseOrder();
    }
    else if (key == "make and model")
    {
        if (ascending)
            carsByMakeAndModel->printInOrder();
        else
            carsByMakeAndModel->printInReverseOrder();
    }
    else if (key == "age")
    {
        if (ascending)
            carsByAge->sortedPrint();
        else
            carsByAge->reversePrint();
    }
    else if (key == "price")
    {
        if (ascending)
            carsByPrice->sortedPrint();
        else
            carsByPrice->reversePrint();
    }
    else
        cout << "Invalid key" << endl;
}

void searchByAge(int age)
{
    int count = 0;
    cout << "Cars sold to age: " << age << endl;
    carsByAge->printValues(age, count);
    cout << "Total cars sold to age " << age << ": " << count << endl;
}


void searchByPriceRange(float start, float end)
{
    cout << "Cars sold between " << start << " and " << end << endl;
    carsByPrice->printRange(start, end);
}

void searchByPrice(float price)
{
    cout << "Cars sold at price: " << price << endl;
    carsByPrice->searchPrice(price);
}


void searchByDateRange(Date start, Date end)
{
    cout << "Cars sold between " << start << " and " << end << endl;

    carsByDate->printInRange(start, end);
}

void searchByCountry(string country)
{
    cout << "Cars sold in " << country << endl;

    carsByCountry->printNodeList(country);
}

void searchByLocation(float latitude, float longitude, int radius)
{
    cout << "Cars sold in region: " << latitude << " and " << longitude << " and " << radius << endl;
    globe->printByRegion(longitude, latitude, radius);
}

void searchByCoordinates(int latitude, int longitude)
{
    cout << "Cars sold at coordinates: " << latitude << " and " << longitude << endl;
    globe->printByCoordinates(longitude, latitude);
}

void printMap()
{
    globe->printRegions();
}

void searchByRectangle(float latitude1, float longitude1, float latitude2, float longitude2)
{
    cout << "Cars sold in: (" << latitude1 << " , " << longitude1 << ") to (" << latitude2 << " , " << longitude2 << ")" << endl;
    globe->printRectangularRegion(longitude1, latitude1, longitude2, latitude2);
}
