// Extended Euclidean Algorithm is an extended version of Euclidean algo
// It main function is to find coefficient (x,y) for which a*x + b*y = gcd(a,b)

/*************************************************************** 
Proof:
    Denote g as GCD(a,b)
    if a=g, b=0 -> g*1 + 0*0 = g => find pair (1,0)
    And to find transition of coefficient fron (a,b) to (b,a%b)
    condition1: b*x1 + (a%b)*y1 = g
    condition2: a*x + b*y = g
    represent (a%b) as a-(a/b)*b, we can get
    b*x1 + [a-(a/b)*b]*y1 = g, and after rearrange will become
    a*y1 + b*[x1-y1*(a/b)] = g
    --
    | x = y1
    | y = x1 - y1*(a/b)
    --
***************************************************************/

#include <iostream>
#include <tuple>

using namespace std;

int GCD_recursive_version(int a, int b, int &x, int &y){
    if (b==0){
        x=1;
        y=0;
        return a;
    }
    int x1, y1;
    int d = GCD_recursive_version(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
    return d;
}

// if we observe, we can find that x*a + y*b = a1, x1*a + y1*b = b1,
// then we can accroding to this properties write following code
// tips: b1 = a1-q*b1, when running code, 
int GCD_iteration_version(int a, int b, int &x, int &y){
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1){
        int q = a1/b1;
        tie(x, x1) = make_tuple(x1, x-q*x1);
        tie(y, y1) = make_tuple(y1, y-q*y1);
        tie(a1,b1) = make_tuple(b1, a1-q*b1);
    }
    return a1;
}

int main(){
    int num1=6, num2=45, co1, co2;
    printf("GCD = %d, Coefficient (x,y) = (%d,%d)\n", 
            GCD_recursive_version(num1, num2, co1, co2), co1, co2);
    num1=76, num2=24;
    printf("GCD = %d, Coefficient (x,y) = (%d,%d)\n", 
            GCD_iteration_version(num1, num2, co1, co2), co1, co2);
}

// Interesting is that if a,b both not equal 0, 
// the larger side coefficient will be negtive
// and the other be positive