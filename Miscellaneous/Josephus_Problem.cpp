// Josephus Problem is a DP Question
// Following function first removing position is k, not 1.
// If want the first removing is started at 1, answer must be (answer-k+n-1)%n+1
#include <bits/stdc++.h>

using namespace std;

// these functions can build 1 to n person from 1 to k per count.
void recursive_build(int n, int k){
    int model[n][k];
    for (int i=1;i<=k;i++){
        for (int j=1;j<=n;j++){
            if (j==1) model[j-1][i-1] = 0;
            else model[j-1][i-1] = (model[j-2][i-1]+i)%j;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<k;j++) cout <<setw(2) <<model[i][j]+1 <<' ';
        cout <<endl;
    }
}


// This function can choice where the order starting at.
// Cons: if want to get 1 to n persons by k, the function will call n times, every function cost n,
// but recursive can do just once, and cost n.
int list_version(vector<int> v, int start, int k){
    // We must use (k-1), 
    // because every time removing the element, the next element will replace it.
    k--; 
    while (v.size()>1){
        v.erase(v.begin()+start);
        start = (start+k)%v.size();
    }
    return v[0];
}

// if we want to know n, just get the answer of n-1 plus k mod n.
// if position start at 1, just plus 1 to the answer of function.
// this function is start at index 0.
int recursive(int n, int k){
    if (n==1) return 0;
    return (recursive(n-1,k)+k)%n;
}
int one_line_recursive(int n, int k){
    return n==1?0:(recursive(n-1,k)+k)%n;
}
// No need to add 1 version
int one_to_n_recursive(int n, int k){
    return n==1?1:(one_to_n_recursive(n-1,k)+k-1)%n+1;
}

int main(){
    cout <<recursive(41,3) <<endl;

    cout <<one_to_n_recursive(41,3) <<endl;

    vector<int> v;
    for (int i=1;i<=41;i++) v.push_back(i);
    cout <<list_version(v,2,3) <<endl;

    recursive_build(10,10);
}