#include <bits/stdc++.h>
#define ll long long

using namespace std;

// Use primality test to find prime
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

// The base cost time of Sieve is O(nloglogn)
// Following functions are all optimized thus less than the base need
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

/********************************************************************************
There is another way can run in O(n)
Although it's also called sieve but, in strictly,
it shouldn't be called since the algorithm is too different from the classic one.
Note:
    This function result may slower than basic Sieve.
    I thought this problem is owing to the input size is too small (maybe)
********************************************************************************/
void sieve_in_linear(int n){
    int min_prime_factor[n+1]{0};
    vector<int> primes;
    for (int i=2;i<=n;i++){
        if (min_prime_factor[i]==0){
            min_prime_factor[i] = i;
            primes.push_back(i);
        }
        size_t sz = primes.size();
        for (int j=0;j<sz && primes[j]<=min_prime_factor[i] && (ll)primes[j]*i<=n;j++)
            min_prime_factor[primes[j]*i] = primes[j];
    }
    // for (int i: primes) cout <<i <<' ';
}

int main(){
	clock_t t;
    int n = 1e5;
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

    t = clock();
    sieve_in_linear(n);
	cout <<"Sieve in linear time complexity cost time: " <<(float)(clock()-t)/CLOCKS_PER_SEC <<endl;
}