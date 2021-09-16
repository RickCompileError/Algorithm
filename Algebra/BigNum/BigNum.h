#ifndef BIGNUM_H
#define BIGNUM_H

#include <bits/stdc++.h>

using namespace std;

const int base = 1e9;

class BigNum{
private:
    vector<int> num;
public:
    BigNum(string s);
    void add(BigNum b);
    void add(string s);
    void subtract(BigNum b);
    void subtract(string s);
    void removeLeadZero();
    size_t size();
};

#endif