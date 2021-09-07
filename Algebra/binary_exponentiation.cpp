// It's an algorithm which allows to calculate a^n using only O(logn) multiplications
// It also can used with any operations that have the property of associativity

#include <iostream>

#define ll long long

using namespace std;

ll binpow_recursive_version(ll a, ll b){
    if (b==0) return 1;
    ll res = binpow_recursive_version(a, b/2);
    if (b%2) return res*res*a;
    else return res*res;
}

ll binpow_iteration_version(ll a, ll b){
    ll res = 1;
    while (b>0){
        if (b&1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

ll binpow_with_modulo(ll a, ll b, ll c){
    ll res = 1;
    while (b>0){
        if (b&1) res = res*a%c;
        a = a*a%c;
        b >>= 1;
    }
    return res;
}

int main(){
    cout <<binpow_recursive_version(2,9) <<endl;
    cout <<binpow_iteration_version(2,9) <<endl;
    cout <<binpow_with_modulo(2,9,3) <<endl;
}