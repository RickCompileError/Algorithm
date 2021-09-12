/***************************************************************************
Euler's totient function is an algo to count
the number of integers between 1 to n inclusive,
which are coprime to n.
ϕ(n) called phi-function
Properties:
    1. if p is prime, ϕ(p) = p-1
    2. if p is prime and k>=1, ϕ(p^k) = p^k- p^(k-1)
    3. if a and b are relatively prime, ϕ(ab) = ϕ(a)*ϕ(b)
    4. if a and b not coprime, ϕ(ab) = ϕ(a)*ϕ(b)*(d/ϕ(d)) with d = gcd(a,b)
    5. ∑d|n ϕ(d) = n
Result:
    using first three properties, we can get
    n = p1^a1 * p2^a2 ..., where pi are prime factors of n
    ϕ(n) = ϕ(p1^a1)*ϕ(p2^a2)...
         = (p1^a1 - p1^(a1-1)) * (p2^a2 - p2^(a2-2))...
         = p1^a1*(1 - (1/p1)) * p2^a2*(1 - (1/p2))...
         = n*(1 - (1/p1))*(1 - (1/p2))...
note: 
    It also have a stupid way by using gcd(a,b) to check
    if two numbers are coprime.
    But if we want to find 1 to n in range, the time complexity is
    O(n^2) (exclude cost time of gcd function)
***************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

// phi-function complexity is O(n^(1/2))
int phi(int n){
    int result = n;
    for (int i=2;i*i<=n;i++){
        if (n%i==0){
            while (n%i==0) n /= i;
            result -= result/i;
        }
    }
    if (n>1) result -= result/n;
    return result;
}

// Euler totient function from 1 to n in O(nloglogn)
// Use phi function is too time consuming
// The concept is same as Sieve of Eratosthenes
void phi_1_to_n(int n){
    vector<int> phi(n+1);
    phi[0] = 0, phi[1] = 1;
    for (int i=2;i<=n;i++) phi[i] = i;
    for (int i=2;i<=n;i++){
        if (phi[i]==i){
            for (int j=i;j<=n;j+=i)
                phi[j] -= phi[j]/i;
        }
    }
    for (int i: phi) cout <<i <<' ';
}

int main(){
    cout <<phi(21) <<endl;
    phi_1_to_n(21); cout <<endl;
}