#include <iostream>

using namespace std;

int GCD_Recursive(int a, int b){
    if (b==0) return a;
    return GCD_Recursive(b, a%b);
}

int GCD_Iteration1(int a, int b){
    while (b){
        a%=b;
        swap(a,b);
    }
    return a;
}

int GCD_Iteration2(int a, int b){
    while ((a%=b) && (b%=a));
    return a+b;
}

int GCD_Ternary(int a, int b){
    return b?GCD_Ternary(b,a%b):a;
}

// modulo is an operation slower than addition, subtraction, bitwise operations
// Binary GCD algorithm can optimize normal Eulidean algorithm
// Three properties:
//  1. both even -> gcd(2a,2b) = 2gcd(a,b)
//  2. one even, one odd -> gcd(2a,b) = gcd(a,b)
//  3. both odd -> gcd(a,b) = gcd(b,a-b)
int GCD_Binary(int a, int b){
    if (!a || !b) return a | b;
    int shift = __builtin_ctz(a|b);
    a >>= __builtin_ctz(a);
    do{
        b >>= __builtin_ctz(b);
        if (a>b) swap(a,b);
        b -= a;
    } while (b);
    return a<<shift;
}


int LCM(int a, int b){
    return a*b/GCD_Recursive(a,b);
}

int main(){
    cout <<GCD_Recursive(6,45) <<endl;
    cout <<GCD_Iteration1(6,45) <<endl;
    cout <<GCD_Iteration2(6,45) <<endl;
    cout <<GCD_Ternary(6,45) <<endl;
    cout <<GCD_Binary(6,45) <<endl;
    cout <<LCM(6,45) <<endl;
}