/// @file tests.cpp
/// @date March 17, 2023

/// 
/// TODO

/// Provided testing file to implement framework based tests in. The examples
/// below demonstrates a basic empty test in each framework with a single
/// assertion. The version uses the supplied catch.hpp file in starter code.
///
/// Assignment details and provided code are created and
/// owned by Adam T Koehler, PhD - Copyright 2023.
/// University of Illinois Chicago - CS 251 Spring 2023

// TODO:
// Choose which framework to keep and delete the other.
//

/*
// Google Test Framework Testing
#include <gtest/gtest.h>
#include "priorityqueue.h"

TEST(classname, one) {
    EXPECT_EQ(true);
}
*/


// Catch 1.0 Framework Testing
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "priorityqueue.h"

using namespace std;

TEST_CASE("(0) no tests") 
{
    REQUIRE(true);
}

TEST_CASE("(1) create empty queue") 
{
    priorityqueue <int> empty;
    REQUIRE(empty.Size()==0);
}
TEST_CASE("(2) add to empty queue") 
{
    priorityqueue <int> empty;
    empty.enqueue(100,2);
    REQUIRE(empty.dequeue()==100);
}
TEST_CASE("(3) check if priority order is correct") 
{
    priorityqueue <int> empty;
    empty.enqueue(100,2);
    empty.enqueue(55,10);
    empty.enqueue(21,3);
    empty.enqueue(99,4);
    empty.enqueue(23,15);
    REQUIRE(empty.dequeue()==100);
   REQUIRE(empty.dequeue()==21);
   REQUIRE(empty.dequeue()==99);
   REQUIRE(empty.dequeue()==55);
   REQUIRE(empty.dequeue()==23);
    REQUIRE(empty.dequeue()==-1);
}
TEST_CASE("(3) check if size works correctly") 
{
    priorityqueue <int> empty;
    REQUIRE(empty.Size()==0);
    empty.enqueue(100,2);
    empty.enqueue(55,10);
    REQUIRE(empty.Size()==2);
    empty.enqueue(21,3);
    empty.enqueue(99,4);
    REQUIRE(empty.Size()==4);
    empty.enqueue(23,15);
    REQUIRE(empty.Size()==5);
   empty.dequeue();
    empty.dequeue();
    empty.dequeue();
    empty.dequeue();
    empty.enqueue(1,1);
    REQUIRE(empty.Size()==2);
}




