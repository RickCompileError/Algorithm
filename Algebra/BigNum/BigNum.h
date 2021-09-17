#ifndef BIGNUM_H
#define BIGNUM_H

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int base = 1e9;

class BigNum{
private:
    vector<int> num;
public:
    BigNum(string s);
    vector<int> getNum();
    void print();
    string toString();
    void add(BigNum b);
    void add(string s);
    void subtract(BigNum b);
    void subtract(string s);
    void multiply(BigNum b);
    void multiply(string s);
    void divide(int n);
    void removeLeadZero();
};

#endif