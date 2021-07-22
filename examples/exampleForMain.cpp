//
// Created by ednow on 2021/7/9.
//
#include <fstream>
#include "gtest/gtest.h"
#include "nlohmann/json.hpp"
#include "utils.h"
#define __debug__


TEST(TestCase, test_PTA_example_for_main) {
    cout << "hello-cpp-1";
}


#ifdef __debug__

#else
int main(){
    return 0;
}
#endif