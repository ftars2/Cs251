/// @filename shape.h
///@author Frank Tarshis
///@date 3/28/2023
///@brief various classes that represent shapes on a canvas
///

#include "iostream"
#pragma once

using namespace std;
/// @brief class used to store the shapes
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
/// @brief creates a generic shape with x and y both 0
Shape::Shape(){
    x=0;
    y=0;
}
/// @brief creates a shape of at the provided cordinates
/// @param x x position
/// @param y y position
Shape::Shape(int x, int y){
    this->x=x;
    this->y=y;
}
/// @brief provides access to the value of a shapes x value 
/// @return the x value of a shape
int Shape:: getX() const {
    return x;
    
}
/// @brief  provides access to the value of a shapes y value 
/// @return the y value of a shape
int Shape:: getY() const {
    return y;
    
}
/// @brief sets the x value of a shape
/// @param a the value x is set to
void Shape:: setX(int a){
    x=a;
}
/// @brief sets the y value of a shape
/// @param a the value x is set to
void Shape:: setY(int a){
    y=a;
}
 /// @brief destructor of the shape class
 Shape:: ~Shape(){

    //destructor
}
/// @brief copy constructor of the shape class
/// @return a copy of the provided shape 
Shape* Shape:: copy(){
   Shape* s= new Shape(x,y);
   return s;
}
/// @brief prints x/y info about the shape
void Shape::printShape() const{
    cout<<"It's a Shape at x: "<<this->getX()<<", y: "<<this->getY()<<endl;
}
/// @brief Class used for Circles, inherits from the shape class
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
/// @brief default constructor for the circle class
Circle::Circle(){
    radius=0;
    x=0;
    y=0;
}
/// @brief constructor for circle class with provided radius
/// @param r radius of the circle
Circle::Circle(int r){
    radius=r;
    x=0;
    y=0;
}
/// @brief constructor for circle when provided with radius and x/y cords
/// @param x x cord of the circle 
/// @param y y cord of the circle
/// @param r radius of the circle
Circle::Circle(int x, int y,int r){
    radius=r;
    this->x=x;
    this->y=y;
}
/// @brief destructor for the circle class
Circle::~Circle(){
    //destructor
}
/// @brief copy constructor for the circle class
/// @return returns a copy of the provided circle 
Circle* Circle::copy(){
 Circle* C= new Circle(x,y,radius);
 return C;   
}
/// @brief returns the radius of the circle in question
/// @return the radius of the circle 
int Circle::getRadius()const{
    return radius;
}
/// @brief sets the radius of a circle
/// @param rad new radus of the circle
void Circle::setRadius(int rad){
    radius=rad;
}
/// @brief prints the circles radius, and x/y cords
void Circle::printShape()const{
    cout<<"It's a Circle at x: "<<x<<", y: "<<y<<", radius: "<<radius<<endl;
}




/// @brief class used for the rectangle class
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
/// @brief default rectangle constructor
Rectangle::Rectangle(){
    width=0;
    height=0;
    x=0;
    y=0;

}
/// @brief rectangle constructor when the width and height are provided
/// @param w provided width
/// @param h provided height
Rectangle::Rectangle(int w, int h){
    width=w;
    height=h;
    x=0;
    y=0;
}
/// @brief rectangle constructor when x/y cords along with width and height are provided
/// @param x provided x
/// @param y provided y
/// @param w provided width
/// @param h provided height
Rectangle::Rectangle(int x, int y, int w, int h){
    width=w;
    height=h;
    this->x=x;
    this->y=y;
}
/// @brief destructor for the rectangle class
Rectangle::~Rectangle(){
}
/// @brief rectangle copy constructor
class Rectangle* Rectangle::copy(){
    Rectangle* rect=new Rectangle;
    rect->width=this->width;
    rect->height=this->height;
    rect->x=this->x;
    rect->y=this->y;
    return rect;
}
/// @brief returns the width of a rectangle
/// @return width of a shape 
int Rectangle::getWidth() const{
return this->width;
}
/// @brief returns the height of a rectangle
/// @return height of rectangle
int Rectangle::getHeight() const{
return this->height;
}
/// @brief sets the width of a rectangle
/// @param wid the provided width of a rectangle 
void Rectangle::setWidth(int wid){
this->width=wid;
}
/// @brief sets the height of a rectangle
/// @param hei the provided height
void Rectangle::setHeight(int hei){
this->height=hei;
}
/// @brief prints info about the rectangle including height, width and x/y position
void Rectangle::printShape()const{
    cout<<"It's a Rectangle at x: "<<this->x<<", y: "<<this->y<<" with width: "<<width<<" and height: "<<height<<endl;
}



/// @brief class used for the Right Triangle class
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
/// @brief default Right Triangle constructor
RightTriangle::RightTriangle(){
    x=0;
    y=0;
    base=0;
    height=0;
}
/// @brief Right Triangle constructor when the base and height are provided
/// @param w provided base
/// @param h provided height
RightTriangle::RightTriangle(int b,int h){
    x=0;
    y=0;
    base=b;
    height=h;
}
/// @brief Right Triangle constructor when x/y cords along with base and height are provided
RightTriangle::RightTriangle(int x, int y, int b,int h){
    this->x=x;
    this->y=y;
    base=b;
    height=h;
}
/// @brief destructor for the Right Triangle class
RightTriangle::~RightTriangle(){
//destructor
}
/// @brief Right Triangle copy constructor
RightTriangle* RightTriangle::copy(){
RightTriangle* R=new RightTriangle(x,y,base,height);
return R;
}
/// @brief returns the base of a Right Triangle
/// @return base of a shape 
int RightTriangle::getBase() const{
return base;
}
/// @brief returns the height of a Right Triangle
/// @return height of Right Triangle
int RightTriangle::getHeight() const{
return height;
}
/// @brief sets the base of a Right Triangle
/// @param b the provided base of a Right Triangle 
void RightTriangle::setBase(int b){
base=b;
}
/// @brief sets the height of a Right Triangle
/// @param h the provided height
void RightTriangle::setHeight(int h){
height=h;
}
/// @brief prints info about the Right Triangle including height, base and x/y position
 void RightTriangle::printShape() const{
cout<<"It's a Right Triangle at x: "<<x<<", y: "<<y<<" with base: "<<base<<" and height: "<<height<<endl;
 }