// Rabin-Karp Algorithm is to find pattern s in text t
// by using hash

#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int p = 31;
const int m = 1e9+9;

vector<int> rabin_karp(string s, string t){
    int S = s.size(), T = t.size();
    
    vector<ll> ppow(max(S,T));
    ppow[0] = 1;
    for (int i=1;i<ppow.size();i++) ppow[i] = ppow[i-1]*p%m;

    vector<ll> hashes(T+1,0);
    for (int i=0;i<T;i++) hashes[i+1] = (hashes[i]+(t[i]-'a'+1)*ppow[i])%m;

    ll value = 0;
    for (int i=0;i<S;i++) value += (s[i]-'a'+1)*ppow[i]%m;

    vector<int> ans;
    for (int i=0;i+S-1<T;i++){
        ll cur = (hashes[i+S]-hashes[i]+m)%m;
        // value*ppow[i]%m can let two hash values both multiply by same exponent
        if (cur == value*ppow[i]%m) ans.push_back(i);
    }
    return ans;
}

int main(){
    string s = "apple";
    string t = "ilikeappleapplelikeme";
    vector<int> rk = rabin_karp(s,t);
    for (int i: rk) cout <<i <<' ';
    cout <<endl;
}