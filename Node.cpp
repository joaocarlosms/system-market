//
// Created by Admin on 16/10/2023.
//

#include "Node.h"

Node::Node() {
    this->father = NULL;
    this->esq = NULL;
    this->dir = NULL;
    this->level = 1;
}

Node::Node(Node *father, Node *esq, Market item, Node *dir, int level) {
    this->father = father;
    this->esq = esq;
    this->dir = dir;
    this->item = item;
    this->level = level;
}

Node::Node(const Node &orig) {
    this->father = orig.getFather();
    this->esq = orig.getEsq();
    this->dir= orig.getDir();
    this->item = orig.getItem();
    this->level = orig.getLevel();
}

void Node::setFather(Node* father) {
    this->father = father;
}

Node* Node::getFather() const {
    return father;
}

void Node::setEsq(Node *esq) {
    this->esq = esq;
}

Node* Node::getEsq() const {
    return esq;
}

void Node::setItem(Market item) {
    this->item = item;
}

Market Node::getItem() const {
    return item;
}

void Node::setDir(Node *dir) {
    this->dir = dir;
}

Node* Node::getDir() const {
    return dir;
}

void Node::setLevel(int level) {
    this->level = level;
}

int Node::getLevel() const {
    return level;
}

int Node::getNumberChilds() {
    if(dir == NULL && esq == NULL)
        return 0; // zero childs;
    else if(dir == NULL && esq != NULL || (dir != NULL && esq == NULL))
        return 1;
    else
        return 2;
}

Node* Node::getOneChild() {
    if(this->getNumberChilds() == 1) {
        if(this->esq != NULL)
            return this->esq;
        else
            return this->dir;
    } else {
        return NULL;
    }
}