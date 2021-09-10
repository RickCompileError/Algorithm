/**************************************************************** 
The goal is to find if any a*x + b*y = c that (x,y) exist
Related problems have:
    find one solution
    find all solution
    find solution in a given interval
    find minimum x+y
Proof:
    The problem is seem like a*x + b*y = GCD(a,b)
    we only need to know that if c%g == 0, 
    then we get the answer a*x*(c/g) + b*y*(c/g) = c/g 
    for (ansx, ansy) = (x*(c/g), y*(c/g))
****************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b, int &x, int &y){
    if (b==0){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
    return d;
}

// The solution is infinite if we can find any one of them
// a*(x+b/g) + b*(y-a/g) = c
// Obviously, it's equal to a*b + b*y = c, and we get the form
// anyX = x + k*b/g, anyY = y - k*a/g, for any k
bool find_any_solution(int a, int b, int c, int &x, int &y, int &g){
    g = gcd(abs(a), abs(b), x, y);
    if (c%g) return false;
    x *= c/g;
    y *= c/g;
    if (a<0) x = -x;
    if (b<0) y = -y;
    return true;
}

void shift_solution(int &x, int &y, int a, int b, int cnt){
    x += cnt*b;
    y -= cnt*a;
}

// record all x when >=minx, <=maxx, >=miny, <=maxy, and then count quantity in range
int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy){
    int x, y, g, lxbound, rxbound, lybound, rybound;
    if (!find_any_solution(a, b, c, x, y, g)) return 0;
    a /= g;
    b /= g;

    int asign = a>0?1:-1;
    int bsign = b>0?1:-1;

    shift_solution(x, y, a, b, (minx-x)/b);
    if (x<minx) shift_solution(x, y, a, b, bsign);
    if (x>maxx) return 0;
    lxbound = x;
    // cout <<"Most closest minx " <<minx <<" : " <<x <<' ' <<y <<' ' <<endl;

    shift_solution(x, y, a, b, (maxx-x)/b);
    if (x>maxx) shift_solution(x, y, a, b, -bsign);
    rxbound = x;
    // cout <<"Most closest maxx " <<maxx <<" : " <<x <<' ' <<y <<' ' <<endl;

    shift_solution(x, y, a, b, -(miny-y)/a);
    if (y<miny) shift_solution(x, y, a, b, -asign);
    if (y>maxy) return 0;
    lybound = x;
    // cout <<"Most closest miny " <<miny <<" : " <<x <<' ' <<y <<' ' <<endl;

    shift_solution(x, y, a, b, -(maxy-y)/a);
    if (y>maxy) shift_solution(x, y, a, b, asign);
    rybound = x;
    // cout <<"Most closest maxy " <<maxy <<" : " <<x <<' ' <<y <<' ' <<endl;

    // because x and y is inversely propotional, we need to check if lybound > rybound
    if (lybound > rybound) swap(lybound, rybound);
    int lx = max(lxbound, lybound);
    int rx = min(rxbound, rybound);
    if (lx>rx) return 0;
    return (rx-lx) / abs(b) + 1;
}

// x' = x + k*(b/g)
// y' = y - k*(a/g)
// x' + y' = x + y + k*(b-a)/g
// constraint is sum > 0
int find_mini_sum(int a, int b, int c){
    int x, y, g, sum;
    find_any_solution(a, b, c, x, y, g);
    sum = x + y;
    if (a!=b){
        // e is displacement
        int e = (b-a) / g;
        // m is coefficient of e
        int m = abs(floor(double(sum)/e));
        // if both pos or neg sign is -1, vice versa
        int sign = ((e>0 && sum>0) || (e<0 && sum<0))?-1:1;
        sum += sign*m*e;
    }
    return sum;
}

int main(){
    int a, b, c, x, y, g;
    a = -6, b = 45, c = 51;
    if (find_any_solution(a, b, c, x, y, g)){
        printf("%d*%d + %d*%d = %d, gcd = %d.\n", a, x, b, y, c, g);
    }else{
        cout <<"No Solution.\n";
    }
    int mnx, mxx, mny, mxy;
    mnx = 0, mxx = 100, mny = -50, mxy = 50;
    printf("Solution in rangeX %d ~ %d, rangeY %d ~ %d = %d.\n",
            mnx, mxx, mny, mxy, find_all_solutions(a, b, c, mnx, mxx, mny, mxy));
    printf("Minimum x + y = %d.\n", find_mini_sum(a, b, c));
}