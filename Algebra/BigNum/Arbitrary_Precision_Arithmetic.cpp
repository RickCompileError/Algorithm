#include "BigNum.h"

int main(){
    BigNum a("10000000000000000000");
    BigNum b("1000000");
    a.add(b);
    cout <<a.toString() <<endl;
    a.subtract(b);
    cout <<a.toString() <<endl;
    a.multiply(b);
    cout <<a.toString() <<endl;
    a.divide(1000000);
    cout <<a.toString() <<endl;
}