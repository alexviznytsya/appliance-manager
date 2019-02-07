/**
 * LinkedList.h
 *
 * Appliance Manager
 *
 * Alex Viznytsya
 * 04/23/2018
 *
 */

#pragma once
#include "AppliancePtr.h"

class LinkedList {
    private:
        class LLNode {
            public:
                LLNode *prev;
                LLNode *next;
                int id;
                AppliancePtr *data;
                LLNode(int i, LLNode *p, LLNode *n);
                ~LLNode();
        };
        LLNode *first;
        LLNode *last;
        int size;
    
       
    public:
        LinkedList();
        LinkedList(int n);
        ~LinkedList();
        void createNode(int i);
        void deleteNode(int i);
        AppliancePtr &getData(int n);
        int getSize();

        
};
