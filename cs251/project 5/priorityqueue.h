/// @file priorityqueue.h
///
///
///
/// Assignment details and provided code are created and
/// owned by Adam T Koehler, PhD - Copyright 2023.
/// University of Illinois Chicago - CS 251 Spring 2023

#pragma once

#include <iostream>
#include <sstream>
#include <set>

using namespace std;

template<typename T>
class priorityqueue {
private:
    struct NODE {
        int priority;  // used to build BST
        T value;  // stored data for the p-queue
        bool dup;  // marked true when there are duplicate priorities
        NODE* parent;  // links back to parent
        NODE* link;  // links to linked list of NODES with duplicate priorities
        NODE* left;  // links to left child
        NODE* right;  // links to right child
    };
    NODE* root;  // pointer to root node of the BST
    int size;  // # of elements in the pqueue
    NODE* curr;  // pointer to next item in pqueue (see begin and next)
    
public:
    //
    // default constructor:
    //
    // Creates an empty priority queue.
    // O(1)
    //
    priorityqueue() {
        root=nullptr;
        size=0;
        curr=nullptr;
        // TO DO: write this function.
        
        
    }
    
    //
    // operator=
    //
    // Clears "this" tree and then makes a copy of the "other" tree.
    // Sets all member variables appropriately.
    // O(n), where n is total number of nodes in custom BST
    //
    priorityqueue& operator=(const priorityqueue& other) {
        this->root=other.root;
        this->curr=other.curr;
        this->size=other.size;
        
        // TO DO: write this function.
        return *this;
        
        
    }
    
    //
    // clear:
    //
    // Frees the memory associated with the priority queue but is public.
    // O(n), where n is total number of nodes in custom BST
    //
    void clear() {
        clearhelp(root);
        // TO DO: write this function.
        
        root=nullptr;
        size=0;
        curr=nullptr;
    }
    
    //
    // destructor:
    //
    // Frees the memory associated with the priority queue.
    // O(n), where n is total number of nodes in custom BST
    //
    ~priorityqueue() {
        clearhelp(root);
        
        // TO DO: write this function.
        
        
    }
    
    //
    // enqueue:
    //
    // Inserts the value into the custom BST in the correct location based on
    // priority.
    // O(logn + m), where n is number of unique nodes in tree and m is number 
    // of duplicate priorities
    //
    void enqueue(T value, int priority) {
        NODE* newn= new NODE;
        newn->dup=false;
        newn->priority=priority;
        newn->value=value;
        newn->left = nullptr;
        newn->right = nullptr;
        newn->link = nullptr;
        if(root==nullptr){
            root=newn;
            newn->parent=nullptr;
            size++;
        }
        else {
        NODE* curr = root;
        NODE* parent = nullptr;

        while (curr != nullptr) {
            parent = curr;
            if (priority < curr->priority){
                curr = curr->left;
            }
            else if (priority > curr->priority){
                curr = curr->right;
            }
            else if(priority == curr->priority) {
                // Duplicate priority found, insert newn into linked list
                newn->link = curr->link;
                curr->link = newn;
                newn->dup = true;
                size++;
                return;
            }
        }

        newn->parent = parent;//inserts a new node if no matching node is found

        if (priority < parent->priority){
            parent->left = newn;
        }
        else{
            parent->right = newn;
        }
    size++;
    }
        // TO DO: write this function.
    }
    //
    // dequeue:
    //
    // returns the value of the next element in the priority queue and removes
    // the element from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number 
    // of duplicate priorities
    //
T dequeue() {
    if (root == nullptr) {
        return -1;
    }

    if (size == 1) {
        T valueOut = root->value;
        delete root;
        root = nullptr;
        size--;
        return valueOut;
    }

    NODE* curr = root;
    while (curr->left != nullptr) {
        curr = curr->left;
    }

    T valueOut = curr->value;
    if (curr == root) {
        root = curr->right;
    }
    else {
        curr->parent->left = curr->right;
    }
    
    if (curr->right != nullptr) {
        curr->right->parent = curr->parent;
    }

    delete curr;
    size--;
    return valueOut;
}
    
    //
    // Size:
    //
    // Returns the # of elements in the priority queue, 0 if empty.
    // O(1)
    //
    int Size() {
        
        
        return this->size; // TO DO: update this return
        
        
    }
    
    //
    // begin
    //
    // Resets internal state for an inorder traversal.  After the
    // call to begin(), the internal state denotes the first inorder
    // node; this ensure that first call to next() function returns
    // the first inorder node value.
    //
    // O(logn), where n is number of unique nodes in tree
    //
    // Example usage:
    //    pq.begin();
    //    while (tree.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;
    void begin() {
        
        
        // TO DO: write this function.
        
        
    }
    
    //
    // next
    //
    // Uses the internal state to return the next inorder priority, and
    // then advances the internal state in anticipation of future
    // calls.  If a value/priority are in fact returned (via the reference
    // parameter), true is also returned.
    //
    // False is returned when the internal state has reached null,
    // meaning no more values/priorities are available.  This is the end of the
    // inorder traversal.
    //
    // O(logn), where n is the number of unique nodes in tree
    //
    // Example usage:
    //    pq.begin();
    //    while (pq.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;
    //
    bool next(T& value, int &priority) {
        
        
        // TO DO: write this function.
        return true; // TO DO: update this return
        
        
    }
    
    //
    // toString:
    //
    // Returns a string of the entire priority queue, in order.  Format:
    // "1 value: Ben
    //  2 value: Jen
    //  2 value: Sven
    //  3 value: Gwen"
    //
    string toString() {
        NODE* cnode=root;
        
        
        // TO DO: write this function.
        string str = "";
        return str; // TO DO: update this return
        
        
    }
    
    //
    // peek:
    //
    // returns the value of the next element in the priority queue but does not
    // remove the item from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number 
    // of duplicate priorities
    //
    T peek() {
        
        
        // TO DO: write this function.
        T valueOut;
        return valueOut; // TO DO: update this return
        
        
    }
    
    //
    // ==operator
    //
    // Returns true if this priority queue as the priority queue passed in as
    // other.  Otherwise returns false.
    // O(n), where n is total number of nodes in custom BST
    //
    bool operator==(const priorityqueue& other) const {
        
        
        // TO DO: write this function.
        return true; // TO DO: update this return
        
        
    }
    
    //
    // getRoot - Do not edit/change!
    //
    // Used for testing the BST.
    // return the root node for testing.
    //
    void* getRoot() {
        return root;
    }
private:

void clearhelp(NODE* stem){
    if(stem==nullptr){
        return;
    }
    if(stem->left!=nullptr){
        clearhelp(stem->left);
}
    if(stem->right!=nullptr){
        clearhelp(stem->right);
}
delete stem;
}

};
