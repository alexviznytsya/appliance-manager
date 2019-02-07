/**
 * LinkedList.cpp
 *
 * Appliance Manager
 *
 * Alex Viznytsya
 * 04/23/2018
 *
 */

#include "LinkedList.h"

LinkedList::LLNode::LLNode(int i, LLNode *p = nullptr, LLNode *n = nullptr) :
id{i}, prev{p}, next{n} {
    this->data = new AppliancePtr(i);
}

LinkedList::LLNode::~LLNode() {
    if(this->data != nullptr) {
        delete this->data;
    }
}

LinkedList::LinkedList(): first{nullptr}, last{nullptr}, size{0} {
};

LinkedList::LinkedList(int n): first{nullptr}, last{nullptr}, size{0} {
    for(int i = 0; i < n; i++) {
        this->createNode(i);
    }
};

LinkedList::~LinkedList() {
    LLNode *curNode = this->first;
    while(curNode != nullptr) {
        LLNode *delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }
};

void LinkedList::createNode(int i) {
    LLNode *tempNode = new LLNode(i, this->last);
    if(this->first == nullptr) {
        this->first = tempNode;
    } else {
        this->last->next = tempNode;
    }
    this->last = tempNode;
    this->size += 1;
}

void LinkedList::deleteNode(int i) {
    LLNode *curNode = this->first;
    while(curNode != nullptr) {
        if(curNode->id == i) {
            if(curNode->prev == nullptr && curNode->next == nullptr) {
                this->first = nullptr;
                this->last = nullptr;
            } else if(curNode->prev == nullptr && curNode->next != nullptr) {
                this->first = curNode->next;
                curNode->next->prev = nullptr;
            } else if(curNode->prev != nullptr && curNode->next == nullptr) {
                curNode->prev->next = nullptr;
                this->last = curNode->prev;
            } else {
                curNode->prev->next = curNode->next;
                curNode->next->prev = curNode->prev;
            }
            delete curNode->data;
            delete curNode;
            this->size -= 1;
        } else {
            curNode = curNode->next;
        }
    }
}

AppliancePtr &LinkedList::getData(int n) {
    LLNode *curNode = this->first;
    while(curNode != nullptr) {
        if(curNode->id == n) {
            break;
        } else {
            curNode = curNode->next;
        }
    }
    return *(curNode->data);
}

int LinkedList::getSize() {
    return this->size;
}
