//
// Created by lnd on 2021/6/21.
//
#include <cstdio>
#include "gtest/gtest.h"

int Maxsize = 1000;

double p(int n, double x) {
    struct stack {
        int no;//保存n
        double val;//保存Pn(x)值
    } st[Maxsize];
    int top = -1, i;//top为栈st的下标值变量
    double fv1 = 1, fv2 = 2 * x; //n=0,n=1时的初值
    for (i = n; i >= 2; i--) {
        top++;
        st[top].no = i;
    }//入栈
    while (top >= 0) {
        st[top].val = 2 * x * fv2 - 2 * (st[top].no - 1) * fv1;
        fv1 = fv2;
        fv2 = st[top].val;
        top--;
    }//出栈
    if (n == 0) {
        return fv1;
    }
    return fv2;
}

double recursion(int n, double x) {
    switch (n) {
        case 0:
            return 1;
        case 1:
            return 2 * x;
        default:
            return 2 * x * recursion(n - 1, x) - 2 * (n - 1) * recursion(n - 2, x);
    }
}

TEST(TestCase, test1) {
//    ASSERT_EQ(p(1,1), recursion(1,1));
//    ASSERT_EQ(p(3,2), recursion(3,2));
    ASSERT_EQ(p(6,5), recursion(6,5));
}