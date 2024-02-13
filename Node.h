//
// Created by Admin on 16/10/2023.
//
#include "Market.h"

using namespace std;

#ifndef MARKET_NODE_H
#define MARKET_NODE_H

class Node {
private:
    Node* father;
    Node* esq;
    Market item;
    Node* dir;
    int level;

public:
    Node();
    Node(Node* father, Node* esq, Market item, Node* dir, int level);
    Node(const Node& orig);
    void setFather(Node* father);
    Node* getFather() const;
    void setEsq(Node* esq);
    Node* getEsq() const;
    void setItem(Market item);
    Market getItem() const;
    void setDir(Node* dir);
    Node* getDir() const;
    void setLevel(int level);
    int getLevel() const;

    Node* getOneChild();
    int getNumberChilds();
};


#endif //MARKET_NODE_H
