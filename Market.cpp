//
// Created by Admin on 16/10/2023.
//

#include "Market.h"

Market::Market() {
    this->id = 0;
    this->name = " ";
    this->price = 0.0;
    this->stock = 0;
    this->cost = 0.0;
}

Market::Market(int id, std::string name, double cost, double price, int stock) {
    this->id = id;
    this->stock = stock;
    this->name = name;
    this->price = price;
    this->cost = cost;
}

Market::Market(const Market &orig) {
    this->id = orig.getId();
    this->name = orig.getName();
    this->price = orig.getPrice();
    this->cost = orig.getCost();
    this->stock = orig.getStock();
}

void Market::setId(int id) {
    this->id = id;
}

int Market::getId() const {
    return id;
}

void Market::setName(string name) {
    this->name = name;
}

string Market::getName() const {
    return name;
}

void Market::setCost(double cost) {
    this->cost = cost;
}

double Market::getCost() const {
    return cost;
}

void Market::setPrice(double price) {
    this->price = price;
}

double Market::getPrice() const {
    return price;
}

void Market::setStock(int stock) {
    this->stock = stock;
}

int Market::getStock() const {
    return stock;
}

void Market::fill_data() {
    cout << "--------------FILL DATAA THIS PRODUCT-------------\n";
    cout << "ID: ";
    cin >> this->id;
    cout << "NAME: ";
    cin.ignore();
    getline(cin, this->name);
    cout << "PRICE: ";
    cin >> this->price;
    cout << "STOCK: ";
    cin >> this->stock;
}

void Market::print_data() {
    cout << left << setw(20) << "ID" << setw(20) << "NAME" << setw(20) << "PRICE" << setw(20) << "COST" << "STOCK\n";
    cout << left << setw(20) << id << setw(20) << name << setw(20) << price << setw(20) << cost << stock << "\n";
}

void Market::print_summarized() {
    cout << "{ " << id << ", " << name << ", " << price << ", " << cost << ", " << stock << "}\n";
}

void Market::copy(const Market& other) {
    this->id = other.getId();
    this->name = other.getName();
    this->price = other.getPrice();
    this->cost = other.getCost();
    this->stock = other.getStock();
}

string Market::printForFile() const {
    string text;
    text = to_string(id) + " " +
            name + " " +
            to_string(price) + " " +
            to_string(cost) + " " +
            to_string(stock);

    return text;
}

bool Market::isEqual(const Market& other) {
    if(id != other.getId())
        return false;
    if(name != other.getName())
        return false;
    if(price != other.getPrice())
        return false;
    if(cost != other.getCost())
        return false;
    if(stock != other.getStock())
        return false;

    return true;
}
