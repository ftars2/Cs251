/// @filename tests.cpp
/// @date March 7, 2023

/// Provided testing file to implement
/// framework based tests in. The example
/// below uses the Catch testing framework
/// version that uses a single .hpp file.

// This tells Catch to provide a main()
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "shape.h"
#include "canvaslist.h"
#include <sstream>
using namespace std;

TEST_CASE("(0) no tests") 
{
  //
  // done
  //
}

// #####################################
// I. TEST CASE 1 -  shape class
// #####################################
TEST_CASE("shape class")
 {
    Shape *s = new Shape;
    REQUIRE(s->getX()==0);
    REQUIRE(s->getY()==0);
    s->setX(15);
    s->setY(25);
    REQUIRE(s->getX()==15);
    REQUIRE(s->getY()==25);
    Shape *ss= s;
    REQUIRE(ss->getX()==15);
    REQUIRE(ss->getY()==25);

    Shape *sss= new Shape(15,25);
    REQUIRE(ss->getY()==sss->getY());
    stringstream output;
    streambuf* oldcout=cout.rdbuf(output.rdbuf());

    s->printShape();
    ss->printShape();

    cout.rdbuf(oldcout);
    REQUIRE(output.str() == "It's a Shape at x: 15, y: 25\nIt's a Shape at x: 15, y: 25\n");
     
}

//
// #####################################
// I. TEST CASE 2 -Circle class
// #####################################
TEST_CASE("Circle class") 
{
      Circle *s = new Circle;
    REQUIRE(s->getX()==0);
    REQUIRE(s->getY()==0);
    s->setX(15);
    s->setY(25);
    s->setRadius(50);
    REQUIRE(s->getX()==15);
    REQUIRE(s->getY()==25);
    Circle *ss= s;
    REQUIRE(ss->getX()==s->getX());
    REQUIRE(ss->getY()==s->getY());
    REQUIRE(ss->getRadius()==s->getRadius());
    Circle *sss= new Circle(15,25,50);
    REQUIRE(sss->getX()==s->getX());
    REQUIRE(sss->getY()==s->getY());
    REQUIRE(sss->getRadius()==s->getRadius());
    
    stringstream output;
    streambuf* oldcout=cout.rdbuf(output.rdbuf());

    s->printShape();
    ss->printShape();

    cout.rdbuf(oldcout);
    REQUIRE(output.str() == "It's a Circle at x: 15, y: 25, radius: 50\nIt's a Circle at x: 15, y: 25, radius: 50\n");
     

}
//
// #####################################
// I. TEST CASE 2 -Rectangle class
// #####################################
TEST_CASE("Rectangle class") 
{
    class Rectangle *s = new class Rectangle;
    REQUIRE(s->getX()==0);
    REQUIRE(s->getY()==0);
    s->setX(15);
    s->setY(25);
    s->setWidth(50);
    s->setHeight(100);
    REQUIRE(s->getX()==15);
    REQUIRE(s->getY()==25);
    REQUIRE(s->getWidth()==50);
    REQUIRE(s->getHeight()==100);
    
    class Rectangle *ss= s;
    REQUIRE(ss->getX()==s->getX());
    REQUIRE(ss->getY()==s->getY());
    REQUIRE(ss->getHeight()==s->getHeight());
    REQUIRE(ss->getWidth()==s->getWidth());
    class Rectangle *sss= new class Rectangle(15,25,50,100);
    REQUIRE(sss->getX()==s->getX());
    REQUIRE(sss->getY()==s->getY());
    REQUIRE(sss->getHeight()==s->getHeight());
    REQUIRE(sss->getWidth()==s->getWidth());
    
    stringstream output;
    streambuf* oldcout=cout.rdbuf(output.rdbuf());

    s->printShape();
    ss->printShape();

    cout.rdbuf(oldcout);
    REQUIRE(output.str() == "It's a Rectangle at x: 15, y: 25 with width: 50 and height: 100\nIt's a Rectangle at x: 15, y: 25 with width: 50 and height: 100\n");
}
//
// #####################################
// I. TEST CASE 3 -Right Triangle class
// #####################################
TEST_CASE("Right Triangle class") 
{
    class RightTriangle *s = new class RightTriangle;
    REQUIRE(s->getX()==0);
    REQUIRE(s->getY()==0);
    s->setX(15);
    s->setY(25);
    s->setBase(50);
    s->setHeight(100);
    REQUIRE(s->getX()==15);
    REQUIRE(s->getY()==25);
    REQUIRE(s->getBase()==50);
    REQUIRE(s->getHeight()==100);
    
    class RightTriangle *ss= s;
    REQUIRE(ss->getX()==s->getX());
    REQUIRE(ss->getY()==s->getY());
    REQUIRE(ss->getHeight()==s->getHeight());
    REQUIRE(ss->getBase()==s->getBase());
    class RightTriangle *sss= new class RightTriangle(15,25,50,100);
    REQUIRE(sss->getX()==s->getX());
    REQUIRE(sss->getY()==s->getY());
    REQUIRE(sss->getHeight()==s->getHeight());
    REQUIRE(sss->getBase()==s->getBase());
    
    stringstream output;
    streambuf* oldcout=cout.rdbuf(output.rdbuf());

    s->printShape();
    ss->printShape();

    cout.rdbuf(oldcout);
    REQUIRE(output.str() == "It's a Right Triangle at x: 15, y: 25 with base: 50 and height: 100\nIt's a Right Triangle at x: 15, y: 25 with base: 50 and height: 100\n");
}

//
// #####################################
// I. TEST CASE 4 -canvas list class - empty
// #####################################
TEST_CASE("Canvaslist class - empty"){
    CanvasList myCanvas;
    REQUIRE(myCanvas.size()==0);
    REQUIRE(myCanvas.front()==nullptr);
    REQUIRE(myCanvas.pop_back()==nullptr);
    REQUIRE(myCanvas.pop_front()==nullptr);
    REQUIRE(myCanvas.isempty()==true);
    CanvasList newcanvas=myCanvas;
    REQUIRE(newcanvas.isempty()==true);
    stringstream output;
    streambuf* oldcout=cout.rdbuf(output.rdbuf());
    myCanvas.draw();
    myCanvas.printAddresses();
    cout.rdbuf(oldcout);
    REQUIRE(output.str() == "");
    REQUIRE(myCanvas.shapeAt(10)==nullptr);
    REQUIRE(myCanvas.shapeAt(0)==nullptr);
    REQUIRE(myCanvas.find(10,10)==-1);
    REQUIRE_NOTHROW(myCanvas.removeAt(0));
    REQUIRE_NOTHROW(myCanvas.clear());    
}

