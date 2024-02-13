//
// Created by Admin on 16/10/2023.
//

#include "Market.h"
#include "Node.h"
#include <fstream>

using namespace std;

#ifndef MARKET_BINARYTREE_H
#define MARKET_BINARYTREE_H

class BinaryTree {
private:
    int quant;
    Node* root; //(raiz)
    int h;

    string saveText = " ";

    Node* inputLocal(Node* subTree, const Market& m);
    Node* smallerDescendant(Node* no);
    Node* higherDescendant(Node* no);
    void removeZeroChild(Node* sair);
    void removeOneChild(Node* sair);
    void removeNchilds(Node* sair);

public:
    BinaryTree();
    BinaryTree(int quant, Node* root);
    BinaryTree(const BinaryTree& orig);
    void setRoot(Node* root);
    Node* getRoot() const;
    void setQuant(int quant);
    int getQuant() const;

    //method find elements in your tree
    Node* find(Node* subTree, const Market& product);
    //method insert
    void insert(Market& product);
    void remove(Market& product);
    Node* getSuccessor(Node* no);
    Node* getPrevious(Node* no);
    int getHeight(Node* no);
    int factorBalance(Node* no);
    void preOrder(Node* no);
    void inOrder(Node* no);
    void posOrder(Node* no);
    void preOrderFile(Node* no);
    void saveProductsInFile();
    void loadProducts();
};


#endif //MARKET_BINARYTREE_H
