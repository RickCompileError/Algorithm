// Preprocess -> O(nlgn)
// Query -> O(1)
// Update -> O(nlgn)
/********************************************************************************* 
Sparse table is a data structure for RMQ (Range Minimum Query).
The only drawback is, that it can only be used on immutable arrays.
To update value, we need to rebuild it. So the cost time is same as preprocess.
It's more common that use segment tree to query a data
which may update value during quering.
*********************************************************************************/

/* Preprocess Program Model
int st[mxN][K+1]; (K >= floor(log(mxN)))
for (int i=0;i<mxN;i++){
    st[i][0] = input[i];
}
for (int i=1;i<=K;i++)
    for (int j=0;j+(1<<i)<=mxN;j++)
        st[j][i] = f(st[j][i-1],st[j+(1<<i-1)][i-1]); (f is function)
*/

#include <bits/stdc++.h>

using namespace std;

int fsum(int a, int b){
    return a+b;
}

int fmin(int a, int b){
    return min(a, b);
}

int fmax(int a, int b){
    return max(a, b);
}

int sz, k;

void print(int **st){
    for (int i=0;i<sz;i++){
        for (int j=0;j<=k;j++){
            cout <<st[i][j] <<' ';
        }
        cout <<endl;
    }
}

int** precompute(vector<int> value, int (*f)(int, int)){
    // initialize
    sz = value.size();
    k = floor(log2(sz));
    int **st = new int*[sz];
    for (int i=0;i<sz;i++) st[i] = new int[k+1]{0};

    for (int i=0;i<sz;i++) st[i][0] = value[i];
    for (int i=1;i<=k;i++)
        for (int j=0;j+(1<<i-1)<sz;j++)
            st[j][i] = f(st[j][i-1],st[j+(1<<i-1)][i-1]);
    return st;
}

int querySum(int **st, int l, int r){
    int sum = 0;
    for (int i=k;i>=0;i--){
        if ((1<<i)<=(r-l+1)){
            sum += st[l][i];
            l += (1<<i);
        }
    }
    return sum;
}

int queryMin(int **st, int l, int r){
    int j = log(r-l+1);
    return min(st[l][j], st[r-(1<<j)+1][j]);
}

int queryMax(int **st, int l, int r){
    int j = log(r-l+1);
    return max(st[l][j], st[r-(1<<j)+1][j]);
}

int main(){
    vector<int> value{3,6,1,6,8,2,8,3,1,5};
    int **st;
    st = precompute(value, fsum);
    cout <<querySum(st, 3, 6) <<endl;
    st = precompute(value, fmin);
    cout <<queryMin(st, 0, 7) <<endl;
    st = precompute(value, fmax);
    cout <<queryMax(st, 1, 6) <<endl;
}