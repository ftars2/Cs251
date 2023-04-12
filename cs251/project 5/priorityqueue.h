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
#include <stdexcept> // for runtime_error

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
    if (this != &other) {
        clear();
        root = copyNodes(other.root, nullptr);
        size = other.size;
        curr = nullptr;
    }
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
                while(curr->dup){
                    curr=curr->link;
                }
                curr->link = newn;
                curr->dup = true;
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
        throw std::runtime_error("Some error message");
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
    if (curr->dup) {
        // Dequeueing node has linked nodes with the same priority
        curr->link->parent = curr->parent;
        curr->link->left = curr->left;
        curr->link->right = curr->right;

        if (curr == root) {
            root = curr->link;
        }
        else {
            if (curr == curr->parent->left) {
                curr->parent->left = curr->link;
            }
            else {
                curr->parent->right = curr->link;
            }
        }

        delete curr;
    }
    else {
        // Dequeueing node does not have linked nodes with the same priority
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
    }
    
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
        curr=root;
        while (curr != nullptr && curr->left != nullptr) {
        curr = curr->left;
        }
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
int lp=0;//left priority
int rp= 0;//right priority
int pp=0;//parent priority
if(curr==nullptr){
    return false;
}
if(curr->dup){
    curr=curr->link;
    value=curr->value;
    priority=curr->priority;
    return true;
}
if(curr->left!=nullptr){
        lp=curr->left->priority - curr->priority;
}        
if(curr->right!=nullptr){
        rp=curr->right->priority - curr->priority;
}
if(curr->parent!=nullptr){
        pp=curr->parent->priority - curr->priority;
}

if(lp>0 && lp<rp && lp<pp){
    curr=curr->left;
    value=curr->value;
    priority=curr->priority;
    return true;
}
if(rp>0 && rp<lp && rp<pp){
    curr=curr->right;
    value=curr->value;
    priority=curr->priority;
    return true;
}
if(pp>0 && pp<rp && pp<lp){
    curr=curr->parent;
    value=curr->value;
    priority=curr->priority;
    return true;
}
curr=nullptr;
return false;

        // TO DO: write this function.
        //return true; // TO DO: update this return
        
        
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
    stringstream output;
    stringhelp(cnode, output);
    string str = output.str();
    return str;
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
           if (root == nullptr) {
        throw std::runtime_error("Some error message");
    }

    if (size == 1) {
        T valueOut = root->value;
        return valueOut;
    }

    NODE* curr = root;
    while (curr->left != nullptr) {
        curr = curr->left;
    }
    T valueOut = curr->value;
    return valueOut;
    }
    
    //
    // ==operator
    //
    // Returns true if this priority queue as the priority queue passed in as
    // other.  Otherwise returns false.
    // O(n), where n is total number of nodes in custom BST
    //
    bool operator==(const priorityqueue& other) const {
        if (size != other.size) {
        return false;
    }
    return isEqual(root, other.root);
}
        // TO DO: write this function.
        
    
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
void stringhelp(NODE* rot, stringstream& output){
    if(rot!=nullptr){
        stringhelp(rot->left, output);
        if(rot->dup){
            NODE* temp=rot;
            while(rot->dup){
                output<<rot->priority <<" value: "<<rot->value<<endl;    
            rot=rot->link;
            }
            output<<rot->priority <<" value: "<<rot->value<<endl;    
        rot=temp;
        }
        if(!rot->dup){
            output<<rot->priority <<" value: "<<rot->value<<endl;
        }
        stringhelp(rot->right, output);
    }    
}

bool isEqual(NODE* node1, NODE* node2) const {
    if (node1 == nullptr && node2 == nullptr) {
        return true;
    }
    else if (node1 == nullptr || node2 == nullptr) {
        return false;
    }
    else if (node1->priority != node2->priority ||
             node1->value != node2->value) {
        return false;
    }
    else {
        return isEqual(node1->left, node2->left) && 
               isEqual(node1->right, node2->right) &&
               isEqual(node1->link, node2->link);
    }
}

// Helper function to recursively copy nodes
NODE* copyNodes(const NODE* otherNode, NODE* parent) {
    if (otherNode == nullptr) {
        return nullptr;
    }
    NODE* newNode = new NODE;
    newNode->priority = otherNode->priority;
    newNode->value = otherNode->value;
    newNode->dup = otherNode->dup;
    newNode->parent = parent;
    newNode->link = copyNodes(otherNode->link, newNode);
    newNode->left = copyNodes(otherNode->left, newNode);
    newNode->right = copyNodes(otherNode->right, newNode);
    return newNode;
}
};
