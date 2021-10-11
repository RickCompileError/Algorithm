// This function precondition is the function f(x) on an interval [l,r] is unimodal
// T(n) = T(2n/3)+1 => Θ(logn)
// Note: By using Master's Theorem, we can get above complexity

#include <bits/stdc++.h>

using namespace std;

double f(double x){
    return -pow(x,2);
}

// eps is used to stop the iteration
double ternary_search(double l, double r){
    double eps = 1e-6;
    while (r-l>eps){
        double m1 = l+(r-l)/3;
        double m2 = r-(r-l)/3;
        double f1 = f(m1);
        double f2 = f(m2);
        if (f1<f2) l = m1;
        else r = m2;
    }
    return f(l);
}

int main(){
    cout <<(int)ternary_search(-5,5);
}