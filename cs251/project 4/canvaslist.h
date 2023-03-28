#pragma once

#include "shape.h"
#include <iostream>

using namespace std;

class ShapeNode
{
    public:
        Shape *value;
        ShapeNode *next;
};

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

CanvasList::CanvasList(){
    listFront=nullptr;
    listSize=0;
}
CanvasList::CanvasList(const CanvasList &other){
    this->listSize=0;
    this->listFront=nullptr;
   ShapeNode *curNode=other.listFront;
   while(curNode!=nullptr){
    push_back(curNode->value->copy());
    curNode=curNode->next;
   } 
}
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

CanvasList::~CanvasList()
{
    clear();
}

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
void CanvasList::push_front(Shape *shape)
{
    ShapeNode *newnode = new ShapeNode;
    newnode->value = shape;
    newnode->next = listFront;
    listFront = newnode;
    listSize++;
}
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
ShapeNode* CanvasList::front() const{
    return this->listFront;

}
bool CanvasList::isempty() const{
    if(listSize==0){
        return true;
    }
    else{
        return false;
    }
}
 int CanvasList::size() const{
    return this->listSize; 
}

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
void CanvasList::draw() const{
    ShapeNode* curnode=listFront;
    while(curnode!=nullptr){
        curnode->value->printShape();
        curnode=curnode->next;
    }
}
void CanvasList::printAddresses() const{
    ShapeNode* curnode=listFront;
    while(curnode!=nullptr){
        cout<<"Node Address: "<<curnode<<"  Shape Address: "<<curnode->value<<endl;
        curnode=curnode->next;
    }
}
