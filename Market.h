//
// Created by Admin on 16/10/2023.
//
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#ifndef MARKET_MARKET_H
#define MARKET_MARKET_H

class Market {
private:
    int id;
    string name;
    double price;
    double cost;
    int stock;

public:
    Market();
    Market(int id, string name, double cost, double price, int stock);
    Market(const Market& orig);
    void setId(int id);
    int getId() const;
    void setName(string name);
    string getName() const;
    void setPrice(double price);
    double getPrice() const;
    void setCost(double cost);
    double getCost() const;
    void setStock(int stock);
    int getStock() const;

    void fill_data();
    void print_data();
    void print_summarized();
    void copy(const Market& other);
    string printForFile() const;
    bool isEqual(const Market& other);
};


#endif //MARKET_MARKET_H
