#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN=1e7+1;
bool num[mxN];
vector<int> prime;

void filter1(){
    for (int i=2;i*i<=mxN;i++){
        if (num[i]) continue;
        for (int j=i*i;j<=mxN;j+=i) num[j]=1;
    }
}

void filter2(){
    for (int i=2;i<mxN;i++){
        bool div=false;
        for (int j=2;j*j<=i && !div;j++){
            if (i%j==0) div=1;
        }
        if (!div) prime.push_back(i);
    }
}

int main(){
	clock_t t = clock();
    filter1();
    // for (int i=2;i<mxN;i++) if (!num[i]) cout <<i <<' ';
	cout <<endl <<"Cost time: " <<(float)(clock()-t)/CLOCKS_PER_SEC <<endl;
    t=clock();
    filter2();
    // for (int i: prime) cout <<i <<' ';
    cout <<endl <<"Cost time: " <<(float)(clock()-t)/CLOCKS_PER_SEC <<endl;
}