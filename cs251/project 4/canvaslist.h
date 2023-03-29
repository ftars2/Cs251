/// @filename canvaslist.h
///@author Frank Tarshis
///@date 3/28/2023
///@brief holds the shapenode class as well as canvaslist class which are used as a linked list of shapes
///
#pragma once

#include "shape.h"
#include <iostream>

using namespace std;
/// @brief used to maintain the linked list of shapes
class ShapeNode
{
    public:
        Shape *value;
        ShapeNode *next;
};
/// @brief acts as a canvas that holds various shapes in specified locations
class CanvasList
{
    private:
        int listSize;
        ShapeNode *listFront;

    public:
        CanvasList();
        CanvasList(const CanvasList &);
        CanvasList operator=(const CanvasList &);
        
        virtual ~CanvasList();
        void clear();
        
        void insertAfter(int, Shape *);
        void push_front(Shape *);
        void push_back(Shape *);
        
        void removeAt(int);
        Shape* pop_front();
        Shape* pop_back();

        ShapeNode* front() const;
        bool isempty() const;
        int size() const;

        int find(int x, int y) const;
        Shape* shapeAt(int) const;
        
        void draw() const;
        void printAddresses() const;
};
/// @brief default constructor for the canvas
CanvasList::CanvasList(){
    listFront=nullptr;
    listSize=0;
}
/// @brief used to make a copy of a canvas
/// @param other  canvas being coppied
CanvasList::CanvasList(const CanvasList &other){
    this->listSize=0;
    this->listFront=nullptr;
   ShapeNode *curNode=other.listFront;
   while(curNode!=nullptr){
    push_back(curNode->value->copy());
    curNode=curNode->next;
   } 
}
/// @brief used to make one canvas equal to another already made canvas
/// @param other the copied canvas
/// @return a copy of the specified canvas
CanvasList CanvasList::operator=(const CanvasList &other){
    
    if (this == &other) {
        return *this;
    }
    clear();
    ShapeNode *curnode = other.listFront;
    while (curnode != nullptr) {
        push_back(curnode->value->copy());
        curnode = curnode->next;
    }
    return *this;
}
/// @brief canvaslist destructor
CanvasList::~CanvasList()
{
    clear();
}
/// @brief clears the canvas
void CanvasList::clear()
{
    while (listFront != nullptr) {
        ShapeNode *nextNode = listFront->next;
        delete listFront->value;
        delete listFront;
        listFront = nextNode;
    }
    listSize = 0;
}
/// @brief insterts a shape after the specifed index
/// @param index specifed index
/// @param shape shape to insert
void CanvasList::insertAfter(int index, Shape *shape)
{
    if (index < 0 || index >= listSize) {
        return;
    }
    ShapeNode *curnode = listFront;
    for (int i = 0; i < index; i++) {
        curnode = curnode->next;
    }
    ShapeNode *newnode = new ShapeNode;
    newnode->value = shape;
    newnode->next = curnode->next;
    curnode->next = newnode;
    listSize++;
}
/// @brief pushs a shape to the front of the list 
/// @param shape the shape being pushed 
void CanvasList::push_front(Shape *shape)
{
    ShapeNode *newnode = new ShapeNode;
    newnode->value = shape;
    newnode->next = listFront;
    listFront = newnode;
    listSize++;
}
/// @brief pushs a shape to the back of a list
/// @param shape the shape being pushed 
void CanvasList::push_back(Shape *shape){
    ShapeNode *newnode= new ShapeNode;
    newnode->value=shape;
    newnode->next=nullptr;
    if(listFront==nullptr){
        listFront=newnode;
    }
    else{
        ShapeNode *curnode=listFront;
        while(curnode->next!=nullptr){
            curnode=curnode->next;
        }
        curnode->next=newnode;
    }
    listSize++;
}
/// @brief remove a shape at a index from the list
/// @param ind index specified 
void CanvasList::removeAt(int ind){
if(ind<0||ind>=listSize||listSize==0){
    return;
}
 if (ind == 0) {
        ShapeNode *temp = listFront;
        listFront = listFront->next;
        delete temp;
        listSize--;
        return;
 }

ShapeNode *curnode=listFront;
for(int i=0;i<ind-1;i++){
curnode=curnode->next;
}
ShapeNode *temp=curnode->next;
curnode->next=temp->next;
delete temp;
listSize--;

}
/// @brief pops a shape from the front of a list and returns it
/// @return the poped shape 
Shape* CanvasList::pop_front(){
    if(listFront==nullptr){
        return nullptr;
    }
    Shape *temp=listFront->value;
    ShapeNode *temp1=listFront;
    listFront=listFront->next;
    listSize--;
delete temp1;

    return temp;
}
/// @brief pops a shape from the back of a list and returns it
/// @return the shape that was at the back
Shape* CanvasList::pop_back(){
    if(listFront==nullptr){
        return nullptr;
    }
    ShapeNode* curnode = listFront;
    if(curnode->next == nullptr){
        Shape *temp = curnode->value;
        delete curnode;
        listFront = nullptr;
        listSize--;
        return temp;
    }
    while(curnode->next->next!=nullptr){
        curnode=curnode->next;
    }  
    Shape *temp=curnode->next->value;
    ShapeNode *temp1=curnode->next;
    curnode->next=nullptr;
    delete temp1;
    listSize--;
    return temp;
}
/// @brief access' the shape that is at the front of the list
/// @return returns a pointer to the shape at the front of the list or null ptr
ShapeNode* CanvasList::front() const{
    return this->listFront;

}
/// @brief checks if the canvas is empty
/// @return true if not empty, false otehrwise
bool CanvasList::isempty() const{
    if(listSize==0){
        return true;
    }
    else{
        return false;
    }
}
 /// @brief returns the size of the list
 /// @return number of shapes in the list
 int CanvasList::size() const{
    return this->listSize; 
}
/// @brief searches the list for a shape with specified x/y cords
/// @param x specifed x cord
/// @param y specified y cord
/// @return the index fo the specified shape
int CanvasList::find(int x, int y) const{
    ShapeNode* curnode=listFront;
    int ind=0;
    while(curnode!=nullptr){
        if((curnode->value->getX()==x)&&(curnode->value->getY()==y)){
            return ind;
        }
        ind++;
        curnode=curnode->next;
    }
    return -1;
}
/// @brief returns a pointer to the shape at the specified ind
/// @param ind specified index 
/// @return  pointer to shape
Shape* CanvasList::shapeAt(int ind) const{
if(ind<0||ind>=listSize){
    return nullptr;
}
int i=0;
ShapeNode* curnode=listFront;
while(i!=ind){
    curnode=curnode->next;
    i++;
}
return curnode->value;
}
/// @brief draws all shapes in the provided list
void CanvasList::draw() const{
    ShapeNode* curnode=listFront;
    while(curnode!=nullptr){
        curnode->value->printShape();
        curnode=curnode->next;
    }
}
/// @brief prints out the memory address of all shapes in the list
void CanvasList::printAddresses() const{
    ShapeNode* curnode=listFront;
    while(curnode!=nullptr){
        cout<<"Node Address: "<<curnode<<"  Shape Address: "<<curnode->value<<endl;
        curnode=curnode->next;
    }
}
