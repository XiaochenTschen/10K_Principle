#define CATCH_CONFIG_MAIN

#include "calculate.cpp"
#include "catch.hpp"

TEST_CASE("testing add"){
    add(10, 20) == 30;
}