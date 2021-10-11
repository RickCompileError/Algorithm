/* 
The prefix function definition is given a string s of length n, 
an array π of length n, where π[i] is the length of the longest proper prefix of the substring s[0…i] 
which is also a suffix of this substring. 
*/

#include <bits/stdc++.h>

using namespace std;

void print(vector<int> v){
    for (int i: v) cout <<i <<' ';
    cout <<endl;
}

// Trivial Algorithm is according to prefix function definition
// and not optimized, O(n^3)
vector<int> trivial_prefix(string s){
    int sz = s.size();
    vector<int> ans(sz);
    for (int i=0;i<sz;i++)
        for (int j=0;j<=i;j++) 
            if (s.substr(0,j)==s.substr(i-j+1,j)) ans[i] = j;
    return ans;
}

// Optimize 1
// π[i+1] can either increase by one, stay the same, or decrease by some amount
// Optimize 2
// if s[i+1] = s[π[i]], then π[i+1] = π[i]+1
// if not, find if s[i+1] = s[π[i-1]] repeatedly until i = 0
// O(n)
vector<int> optimize_prefix(string s){
    int sz = s.size();
    vector<int> ans(sz);
    for (int i=1;i<sz;i++){
        int j = ans[i-1];
        while (j>0 && s[j]!=s[i]) j = ans[j-1];
        if (s[j]==s[i]) j++;
        ans[i] = j;
    }
    return ans;
}

// Knuth-Morris-Pratt algorithm
// It can help us to find all the positions of the string in the text t.
// Assume that s = "abc", t = "abcabc".
// Combining them with a seperator in middle, we can get the string "abc abcabc", 
// then using prefix function to find answer.
vector<int> search_string(string s, string t){
    string combine = s+" "+t;
    int S = s.size(), T = t.size(), C = combine.size();
    vector<int> u = optimize_prefix(combine);
    vector<int> ans;
    for (int i=0;i<C;i++) if (u[i]==S) ans.push_back(i-2*S);
    return ans;
}

// Three steps:
// 1. get prefix vector and plus to answer
// 2. dp, ans[π[i-1]] += ans[i], optimize 2 concept
// 3. increase by one, since we also need to count prefix string itself
vector<int> count_prefix(string t){
    int sz = t.size();
    vector<int> u = optimize_prefix(t);
    vector<int> ans(sz+1);
    for (int i=0;i<sz;i++) ans[u[i]]++;
    for (int i=sz-1;i>0;i--) ans[u[i-1]] += ans[i];
    for (int i=0;i<=sz;i++) ans[i]++;
    return ans;
}

vector<int> count_string_prefix(string s, string t){
    string combine = s+" "+t;
    int S = s.size(), T = t.size(), C = combine.size();
    vector<int> u = optimize_prefix(combine);
    vector<int> ans(S+1);
    for (int i=S+1;i<C;i++) ans[u[i]]++;
    for (int i=S;i>0;i--) ans[u[i-1]] += ans[i];
    return ans;
}

int count_diff_substring(string s){
    reverse(s.begin(),s.end());
    vector<int> rev = optimize_prefix(s);
    int ans=0;
    for (int i=0;i<s.size();i++) ans += i+1-rev[i];
    return ans;
}

int main(){
    string s = "abca", t = "abcabckkkabc";
    print(trivial_prefix(t));
    print(optimize_prefix(t));
    print(search_string(s,t));
    print(count_prefix(t));
    print(count_string_prefix(s,t));
    cout <<count_diff_substring(s) <<endl;
}