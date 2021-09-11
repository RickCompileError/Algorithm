#include <bits/stdc++.h>
#define ll long long

using namespace std;

void two_loop(int n){
    vector<int> primes;
    for (int i=2;i<n;i++){
        bool div=false;
        for (int j=2;j*j<=i && !div;j++){
            if (i%j==0) div=1;
        }
        if (!div) primes.push_back(i);
    }
    // for (int i: primes) cout <<i <<' ';
}

vector<bool> sieve(int n){
    vector<bool> primes(n+1, true);
    primes[0] = primes[1] = false;
    for (int i=2;i*i<=n;i++){
        if (!primes[i]) continue;
        for (int j=i*i;j<=n;j+=i) primes[j] = false;
    }
    // for (int i=2;i<=n;i++) if (primes[i]) cout <<i <<' ';
    return primes;
}

vector<ll> pregenerator(ll n){
    vector<bool> mark(sieve(n));
    vector<ll> primes;
    size_t sz = mark.size();
    for (int i=0;i<sz;i++) if (mark[i]) primes.push_back(i);
    return primes;
}

void sieve_range(ll l, ll r){
    // use pregenerator to optimize program
    vector<bool> primes((r-l+1), true);
    vector<ll> pre(pregenerator(sqrt(r)));
    for (ll i: pre)
        for (ll j = max(i*i, (ll)ceil((double)l/i)*i);j<=r;j+=i)
            primes[j-l] = false;
    if (l==1) primes[0] = false;
    // for (int i=0;i<primes.size();i++) if (primes[i]) cout <<i+l <<' ';
}

void sieve_range_no_pregen(int l, int r){
    vector<bool> primes(r-l+1, true);
    ll lmt = sqrt(r);
    for (ll i=2;i<=lmt;i++)
        for (ll j=max(i*i, (ll)ceil((double)l/i)*i);j<=r;j+=i)
            primes[j-l] = false;
    if (l==1) primes[0] = false;
    // for (int i=0;i<primes.size();i++) if (primes[i]) cout <<i+l <<' ';
}

int main(){
	clock_t t;
    int n = 1e6;
    ll left = 1e3, right = 1e6;

    t=clock();
    two_loop(n);
    cout <<"Two loop cost time: " <<(float)(clock()-t)/CLOCKS_PER_SEC <<endl;

    t = clock();
    sieve(n);
	cout <<"Sieve cost time: " <<(float)(clock()-t)/CLOCKS_PER_SEC <<endl;

    t = clock();
    sieve_range(left, right);
	cout <<"Sieve range cost time: " <<(float)(clock()-t)/CLOCKS_PER_SEC <<endl;

    t = clock();
    sieve_range_no_pregen(left, right);
	cout <<"Sieve range with no pregenerate cost time: " <<(float)(clock()-t)/CLOCKS_PER_SEC <<endl;
}