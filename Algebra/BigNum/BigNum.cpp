// this class only do positive operations
#include "BigNum.h"

BigNum::BigNum(string s){
    for (int i=(int)s.length();i>0;i-=9){
        if (i<9) num.push_back(stoi(s.substr(0,i)));
        else num.push_back(stoi(s.substr(i-9,i)));
    }
}

void BigNum::removeLeadZero(){
    while (num.size()>1 && num.back()==0) num.pop_back();
}

vector<int> BigNum::getNum(){
    return vector<int>(num);
}

void BigNum::print(){
    cout <<(num.empty()?0:num.back());
    for (int i=num.size()-2;i>=0;i--) printf("%09d",num[i]);
}

string BigNum::toString(){
    string s = "";
    stringstream ss;
    s = s + (num.empty()?"0":to_string(num.back()));
    for (int i=num.size()-2;i>=0;i--){
        ss <<setw(9) <<setfill('0') <<num[i];
        s = s + ss.str();
    }
    return s;
}

void BigNum::add(BigNum b){
    vector<int> v = b.getNum();
    int carry = 0;
    for (size_t i=0;i<max(num.size(),v.size()) || carry;i++){
        if (i==num.size()) num.push_back(0);
        num[i] += carry + (i<v.size()?v[i]:0);
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
    vector<int> v = b.getNum();
    int carry = 0;
    for (size_t i=0;i<v.size() || carry;i++){
        num[i] -= carry + (i<v.size()?v[i]:0);
        carry = num[i]<0;
        if (carry) num[i] += base;
    }
    removeLeadZero();
}

void BigNum::subtract(string s){
    BigNum b(s);
    subtract(b);
}

void BigNum::multiply(BigNum b){
    vector<int> v = b.getNum();
    vector<int> result(num.size()+v.size());
    int carry = 0, mul;
    for (size_t i=0;i<num.size();i++){
        for (size_t j=0;j<v.size() || carry;j++){
            mul = result[i+j] + num[i]*(j<num.size()?v[j]:0)*1ll + carry;
            result[i+j] = mul%base;
            carry = mul/base;
        }
    }
    num = result;
    removeLeadZero();
}

void BigNum::multiply(string s){
    BigNum b(s);
    subtract(b);
}

// I only done big number divided by int
// the function can't do big num divide big num :(
void BigNum::divide(int n){
    ll carry = 0, complement;
    for (int i=num.size()-1;i>=0;i--){
        complement = num[i] + carry*base*1ll;
        num[i] = complement/n;
        carry = complement%n;
    }
    removeLeadZero();
}