#include <iostream>
#include <vector>
#include <cmath>

#define ll long long

using namespace std;

// just repeatedly divide by prime
// O(n^(1/2))
void trial_division(ll n){
    vector<ll> factor;
    for (ll i=2;i*i<=n;i++){
        while (n%i==0){
            factor.push_back(i);
            n/=i;
        }
    }
    if (n>1) factor.push_back(n);
    for (int i: factor) cout <<i <<' ';
}

// Optimization of trial.
// The idea is divide by 2 until can't divisible, then we only need to check odd numbers
// It's can also be extended, but we need to find regular pattern among remaining numbers
void wheel_factorization(ll n){
    vector<ll> factor;
    while (n%2==0){
        factor.push_back(2);
        n/=2;
    }
    for (ll i=3;i*i<=n;i+=2){
        while (n%i==0){
            factor.push_back(i);
            n/=i;
        }
    }
    if (n>1) factor.push_back(n);
    for (int i: factor) cout <<i <<' ';
}

// Precomputed primes by using sieve
vector<ll> sieve(ll n){
    vector<bool> mark(n+1, true);
    mark[0] = mark[1] = false;
    for (int i=2;i*i<=n;i++){
        if (!mark[i]) continue;
        for (int j=i*i;j<=n;j+=i) mark[j] = false;
    }
    vector<ll> primes;
    size_t sz = mark.size();
    for (int i=0;i<sz;i++) if (mark[i]) primes.push_back(i);
    return primes;
}
void precompute(ll n){
    vector<ll> primes = sieve(sqrt(n));
    vector<ll> factor;
    for (ll i: primes){
        if (i*i>n) break;
        while (n%i==0){
            factor.push_back(i);
            n/=i;
        }
    }
    if (n>1) factor.push_back(n);
    for (int i: factor) cout <<i <<' ';
}

int main(){
    trial_division(100);cout <<endl;
    wheel_factorization(100); cout <<endl;
    precompute(100); cout <<endl;
}