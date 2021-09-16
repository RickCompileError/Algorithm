// this class only do positive operations
#include "BigNum.h"

BigNum::BigNum(string s){
    for (int i=(int)s.length();i>0;i-=9){
        if (i<9) num.push_back(atoi(s.substr(0,i).c_str()));
        else num.push_back(atoi(s.substr(i-9,i).c_str()));
    }
}

void BigNum::removeLeadZero(){
    while (num.size()>1 && num.back()==0) num.pop_back();
}

size_t BigNum::size(){
    return num.size();
}

void BigNum::add(BigNum b){
    int carry = 0;
    for (size_t i=0;i<max(size(),b.size()) || carry;i++){
        if (i==size()) num.push_back(0);
        num[i] += carry + (i<b.size()?b.num[i]:0);
        carry = num[i]>=base;
        if (carry) num[i] -= base;
    }
}

void BigNum::add(string s){
    BigNum b(s);
    add(b);
}

// the function only accept a>b
void BigNum::subtract(BigNum b){
    int carry = 0;
    for (size_t i=0;i<b.size() || carry;i++){
        num[i] -= carry + (i<b.size()?b.num[i]:0);
        carry = num[i]<0;
        if (carry) num[i] += base;
    }
    removeLeadZero();
}

void BigNum::subtract(string s){
    BigNum b(s);
    subtract(b);
}