/**************************************************************************
String Hashing is to convert a string into an integer.
If two strings s and t are equal, then also their hashes have to be equal.
Opposite direction doesn't have to hold.
To reduce collision probability, we can use two different hash functions
at the same time.
**************************************************************************/

#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int p = 31;
const int m = 1e9+9;
const int mxn = 1e5;
ll dp[mxn];
ll ppow[mxn];

// Polynomial rolling hash function
// It's reasonable to make p a prime number roughly equal to the number of input character
// hash(s) = s[0]+s[1]⋅p+s[2]⋅p^2+...+s[n−1]⋅p^(n−1) mod m=
//         = ∑(i=0~n−1) s[i]⋅p^i mod m,
ll compute_hash(string s){
    const int p = 31;
    const int m = 1e9+9;
    ll v = 0;
    ll ppow = 1;
    for (char c: s){
        v += (c-'a'+1)*ppow%m;
        ppow = ppow*p%m;
    }
    return v;
}

vector<vector<int>> find_duplicate_strings(vector<string> v){
    int n = v.size();
    vector<pair<ll,int>> hashes(n);
    for (int i=0;i<n;i++) hashes[i] = {compute_hash(v[i]),i};
    sort(hashes.begin(), hashes.end());
    vector<vector<int>> ans;
    for (int i=0;i<n;i++){
        if (i==0 || hashes[i].first!=hashes[i-1].first)
            ans.emplace_back();
        ans.back().push_back(hashes[i].second);
    }
    return ans;
}

// Build the hash value 0,0~1,0~2,0~n-1 and p power from 0 to n-1
void init(string s){
    int n = s.size();
    dp[1] = (s[0]-'a'+1)%m;
    ppow[0] = 1;
    for (int i=1;i<n;i++){
        ppow[i] = ppow[i-1]*p%m;
        dp[i+1] = (dp[i]+ppow[i]*(s[i]-'a'+1))%m;
    }
}

// According to previous proof, to find l to r substring, 
// we must find hash(s[0...j])-hash(s[0...i-1]) mod m and divided by p^i.
// The above method must use modular multiplicative inverse to find answer, 
// but it can just multiply p^(r-l) to confirm if two substrings are same.
// Tips1: if i<j subj is multiply by p^j, and subi by p^i, subi then multiply by p^(j-i),
// and they can easily be compared.
// Tips2: this function can't get the real hash value, it is used to compare
// if two strings are same.
ll sub_hash(string s, int l, int r){
    ll v = (dp[r]-dp[l]+m)%m;
    v = v*ppow[s.size()-l-1]%m;
    return v;
}

ll find_all_substring(string s){
    int n = s.size();
    int ans = 0;
    set<ll> hs;
    for (int l=1;l<=n;l++){
        set<ll> hs;
        for (int i=0;i<=n-l;i++) hs.insert(sub_hash(s,i,i+l));
        ans += hs.size();
    }
    return ans;
}

int main(){
    string s = "abbbc";
    cout <<compute_hash(s) <<endl <<endl;
    vector<string> v{"abc","def","qwert","apple","banana","abc"};
    vector<vector<int>> group = find_duplicate_strings(v);
    for (vector<int> i: group){
        for (int j: i) cout <<j <<' ';
        cout <<endl;
    }
    cout <<endl;
    init(s);
    cout <<find_all_substring(s) <<endl;
}