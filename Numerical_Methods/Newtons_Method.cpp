#include <bits/stdc++.h>

using namespace std;

double f(double x){
    return pow(x,2)+x;
}

double diff_f(double x){
    return 2*x;
}

double newton(double x){
    double eps = 1e-9;
    double ax;
    while (1){
        ax = x-f(x)/diff_f(x);
        if (abs(x-ax)<eps) break;
        x = ax;
    }
    return x;
}

int main(){
    cout <<newton(10) <<endl;
}