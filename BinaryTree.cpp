//
// Created by Admin on 16/10/2023.
//

#include "BinaryTree.h"

BinaryTree::BinaryTree() {
    this->root = NULL;
    this->quant = 0;
    this->h = 1;
}

BinaryTree::BinaryTree(int quant, Node *root) {
    this->root = root;
    this->quant = quant;
}

BinaryTree::BinaryTree(const BinaryTree &orig) {
    this->root = orig.getRoot();
    this->quant = orig.getQuant();
}

void BinaryTree::setQuant(int quant) {
    this->quant = quant;
}

int BinaryTree::getQuant() const {
    return quant;
}

void BinaryTree::setRoot(Node *root) {
    this->root = root;
}

Node* BinaryTree::getRoot() const {
    return root;
}

Node* BinaryTree::inputLocal(Node *node, const Market &m) { // find the father of new produc
    Market item = node->getItem();
    if(m.getId() < item.getId()) {
        if(node->getEsq() != NULL)
            return inputLocal(node->getEsq(), m);
    } else {
        if(node->getDir() != NULL)
            return inputLocal(node->getDir(), m);
    }
    return node; // return the father of new product
}

Node* BinaryTree::find(Node *subTree, const Market &product) {
    if(subTree != NULL) {
        Market item = subTree->getItem();
        if(product.getId() < item.getId())
            return find(subTree->getEsq(), product);
        else if(product.getId() > item.getId())
            return find(subTree->getDir(), product);
        else
            return subTree;
    } else {
        cout << "Invalid Operation! Element foundn't\n";
        return NULL;
    }
}

void BinaryTree::insert(Market& product) {
    Node* newNode = new Node();
    newNode->setItem(product);

    if(root == NULL) {
        root = new Node();
        root->setItem(product);
        quant++;
    } else {
        Node* father = this->inputLocal(root, product);

        Market itemFather = father->getItem();
        if(product.getId() < itemFather.getId()) {
            father->setEsq(newNode);
            newNode->setFather(father);
            quant++;
        } else if(product.getId() > itemFather.getId()){
            father->setDir(newNode);
            newNode->setFather(father);
            quant++;
        } else {
            cout << "ERROR! This element already exist\n";
        }
    }
}

void BinaryTree::remove(Market &product) {
    Node* sair = find(root, product);

    int numberChilds = sair->getNumberChilds();
    if(numberChilds == 0)
        this->removeZeroChild(sair);
    else if(numberChilds == 1)
        this->removeOneChild(sair);
    else
        this->removeNchilds(sair);

    quant--;
}

Node* BinaryTree::smallerDescendant(Node *no) {
    if(no != NULL) {
        if(no->getEsq() == NULL) // percorre a sub-arvore da direita so q pela esquerda
            return no;
        else
            return smallerDescendant(no->getEsq());
    } else {
        return NULL;
    }
}

Node* BinaryTree::getSuccessor(Node *no) {
    if(no != NULL) {
        return smallerDescendant(no->getDir());
    } else {
        cout << "This node own not previous!\n";
        return NULL;
    }
}

Node* BinaryTree::higherDescendant(Node *no) {
    if(no != NULL) {
        if(no->getDir() == NULL)
            return no;
        else
            return higherDescendant(no->getDir());
    } else {
        return NULL;
    }
}

Node* BinaryTree::getPrevious(Node *no) {
    if(no != NULL) {
        return higherDescendant(no->getEsq());
    } else {
        cout << "This node own not previous!\n";
        return NULL;
    }
}

void BinaryTree::removeZeroChild(Node *sair) {
    Node* father = sair->getFather();

    if(father == NULL) {
        root = NULL;
    } else {
        Market itemFather = father->getItem();
        Market itemSair = sair->getItem();

        if(itemSair.getId() < itemFather.getId())
            father->setEsq(NULL);
        else
            father->setDir(NULL);
    }
}

void BinaryTree::removeOneChild(Node *sair) {
    Node* father = sair->getFather();
    Node* child = sair->getOneChild();

    if(father == NULL) {
        father = child;
    } else {
        if(child != NULL) {
            child->setFather(father);
            if(child->getItem().getId() > father->getItem().getId())
                father->setDir(child);
            else
                father->setEsq(child);
        }
    }
}

void BinaryTree::removeNchilds(Node *sair) {
    Node* previous = this->getPrevious(sair);

    Market m = sair->getItem();
    this->remove(m);

    sair->setItem(previous->getItem());
}

int BinaryTree::getHeight(Node *no) {
    if(no == NULL) {
        return 0;
    } else {
        int h_esq = getHeight(no->getEsq());
        int h_dir = getHeight(no->getDir());

        if(h_esq > h_dir)
            return h_esq + 1;
        else
            return h_dir + 1;
    }
}

int BinaryTree::factorBalance(Node *no) {
    int h_esq = 0, h_dir = 0;

    Node* subTreeEsq = no->getEsq();
    Node* subTreeDir = no->getDir();

    if(subTreeEsq != NULL)
        h_esq = this->getHeight(subTreeEsq);
    else
        h_dir = this->getHeight(subTreeDir);

    return h_dir - h_esq;
}

void BinaryTree::preOrder(Node *no) {
    if(no != NULL) {
        cout << "(" << no->getItem().getId() << ", " << no->getItem().getName() << ", " << no->getItem().getPrice()
        << ", " << no->getItem().getCost() << ", " << no->getItem().getStock() << ")\n";

        preOrder(no->getEsq());
        preOrder(no->getDir());
    }
}

void BinaryTree::inOrder(Node *no) {
    if(no != NULL) {
        inOrder(no->getEsq());

        cout << "(" << no->getItem().getId() << ", " << no->getItem().getName() << ", " << no->getItem().getPrice()
        << ", " << no->getItem().getCost() << ", " << no->getItem().getStock() << ")\n";

        inOrder(no->getDir());
    }
}

void BinaryTree::posOrder(Node *no) {
    if(no != NULL) {
        posOrder(no->getEsq());
        posOrder(no->getDir());

        cout << "(" << no->getItem().getId() << ", " << no->getItem().getName() << ", " << no->getItem().getPrice()
        << ", " << no->getItem().getCost() << ", " << no->getItem().getStock() << ")\n";
    }
}

void BinaryTree::preOrderFile(Node *no) {
    if(no != NULL) {
        saveText = saveText + no->getItem().printForFile() + "\n";
        preOrderFile(no->getEsq());
        preOrderFile(no->getDir());
    }
}

void BinaryTree::saveProductsInFile() {
    string pathPaste = "Products.txt";
    ofstream saveFile;
    saveFile.open(pathPaste.c_str(), ios::app);

    if(!saveFile.is_open())
        cout << "Invalid operation! File not found\n";
    else {
        preOrderFile(root);
        saveFile << quant << endl << saveText << endl;
    }
    saveFile.close();
}

void BinaryTree::loadProducts() {
    string pathPaste = "Products.txt";
    ifstream readFile;
    readFile.open(pathPaste.c_str(), ios::app);

    if(!readFile.is_open())
        cout << "ERROR! File not found\n";
    else {
        int quant;
        readFile >> quant;

        string name;
        int id, stock;
        double price, cost;

        Market m;
        for(int i = 0; i < quant; i++) {
            readFile >> id;
            readFile >> name;
            readFile >> price;
            readFile >> cost;
            readFile >> stock;

            m.setId(id);
            m.setName(name);
            m.setPrice(price);
            m.setCost(cost);
            m.setStock(stock);

            insert(m);
        }
    }
    readFile.close();
}

