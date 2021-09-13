/*****************************************************
MMI of an integer a is an integer x such that
a*x is congruent to 1 modular some modulus m.
Formal presentation: a⋅x ≡ 1 mod m.
MMI exist if and only if a and m are coprime,
it means gcd(a, m) = 1
*****************************************************/
#include <iostream>

using namespace std;

int extended_euclidean(int a, int m, int &x, int &y){
    if (m==0){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_euclidean(m, a%m, x1, y1);
    x = y1;
    y = x1 - y1*(a/m);
    return d;
}

void MMI(int a, int m){
    int x, y;
    int g = extended_euclidean(a, m, x, y);
    if (g!=1){
        cout <<"No solution\n";
    }else{
        // plus m is because x may be negative, we need to change it to positive
        x = (x%m + m) % m;
        cout <<x <<endl;
    }
}

// There is an algo can compute 1~m-1 MMI in O(m), but the condition is
// modulus m is prime.
void mod_inv_all_num(int m){
    int inv[m+1];
    inv[0] = 0, inv[1] = 1;
    for (int i=2;i<=m;i++) inv[i] = m - (m/i) * inv[m%i] % m;
}

int main(){
    int a, m;
    a = 5, m = 3;
    MMI(a,m);
}