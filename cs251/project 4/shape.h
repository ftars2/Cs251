#include "iostream"
#pragma once

using namespace std;

class Shape
{
    protected:
        int x;
        int y;

    public: 
        Shape();
        Shape(int x, int y);
        virtual ~Shape();
        virtual Shape* copy();

        int getX() const;
        int getY() const;
        void setX(int);
        void setY(int);
        
        virtual void printShape() const;
};
Shape::Shape(){
    x=0;
    y=0;
}
Shape::Shape(int x, int y){
    this->x=x;
    this->y=y;
}
int Shape:: getX() const {
    return x;
    
}
int Shape:: getY() const {
    return y;
    
}
void Shape:: setX(int a){
    x=a;
}
void Shape:: setY(int a){
    y=a;
}
 Shape:: ~Shape(){

    //destructor
}
Shape* Shape:: copy(){
   Shape* s= new Shape(x,y);
   return s;
}
void Shape::printShape() const{
    cout<<"It's a Shape at x: "<<this->getX()<<", y: "<<this->getY()<<endl;
}

class Circle : public Shape 
{
    private:
        int radius;

    public: 
        Circle();
        Circle(int r);
        Circle(int x, int y, int r);

        virtual ~Circle();
        virtual Circle* copy();
        
        int getRadius() const;
        void setRadius(int);
        
        virtual void printShape() const;
};
Circle::Circle(){
    radius=0;
    x=0;
    y=0;
}
Circle::Circle(int r){
    radius=r;
    x=0;
    y=0;
}
Circle::Circle(int x, int y,int r){
    radius=r;
    this->x=x;
    this->y=y;
}
Circle::~Circle(){
    //destructor
}
Circle* Circle::copy(){
 Circle* C= new Circle(x,y,radius);
 return C;   
}
int Circle::getRadius()const{
    return radius;
}
void Circle::setRadius(int rad){
    radius=rad;
}
void Circle::printShape()const{
    cout<<"It's a Circle at x: "<<x<<", y: "<<y<<", radius: "<<radius<<endl;
}


class Rectangle : public Shape 
{
    private:
        int width;
        int height;

    public: 
        Rectangle();
        Rectangle(int w, int h);
        Rectangle(int x, int y, int w, int h);
        
        virtual ~Rectangle();
        virtual Rectangle* copy();
        
        int getWidth() const;
        int getHeight() const;
        void setWidth(int);
        void setHeight(int);
        
        virtual void printShape() const;
};

Rectangle::Rectangle(){
    width=0;
    height=0;
    x=0;
    y=0;

}

Rectangle::Rectangle(int w, int h){
    width=w;
    height=h;
    x=0;
    y=0;
}
Rectangle::Rectangle(int x, int y, int w, int h){
    width=w;
    height=h;
    this->x=x;
    this->y=y;
}
Rectangle::~Rectangle(){
}
Rectangle* Rectangle::copy(){
    Rectangle* rect=new Rectangle;
    rect->width=this->width;
    rect->height=this->height;
    rect->x=this->x;
    rect->y=this->y;
    return rect;
}
int Rectangle::getWidth() const{
return this->width;
}
int Rectangle::getHeight() const{
return this->height;
}
void Rectangle::setWidth(int wid){
this->width=wid;
}
void Rectangle::setHeight(int hei){
this->height=hei;
}
void Rectangle::printShape()const{
    cout<<"It's a Rectangle at x: "<<this->x<<", y: "<<this->y<<"with width: "<<width<<" and height: "<<height<<endl;
}


class RightTriangle : public Shape 
{
    private:
        int base;
        int height;

    public: 
        RightTriangle();
        RightTriangle(int b, int h);
        RightTriangle(int x, int y, int b, int h);
        
        virtual ~RightTriangle();
        virtual RightTriangle* copy();
        
        int getBase() const;
        int getHeight() const;
        void setBase(int);
        void setHeight(int);

        virtual void printShape() const;
};
RightTriangle::RightTriangle(){
    x=0;
    y=0;
    base=0;
    height=0;
}
RightTriangle::RightTriangle(int b,int h){
    x=0;
    y=0;
    base=b;
    height=h;
}
RightTriangle::RightTriangle(int x, int y, int b,int h){
    this->x=x;
    this->y=y;
    base=b;
    height=h;
}
RightTriangle::~RightTriangle(){
//destructor
}
RightTriangle* RightTriangle::copy(){
RightTriangle* R=new RightTriangle(x,y,base,height);
return R;
}

int RightTriangle::getBase() const{
return base;
}
int RightTriangle::getHeight() const{
return height;
}
void RightTriangle::setBase(int b){
base=b;
}
void RightTriangle::setHeight(int h){
height=h;
}
 void RightTriangle::printShape() const{
cout<<"It's a Right Triangle at x: "<<x<<", y: "<<y<<" with base: "<<base<<" and height: "<<height<<endl;
 }