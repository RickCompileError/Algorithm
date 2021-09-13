/* 
 * Balanced Ternary is a non-standard but positional numeral system.
 * The digits can have 1, 0, -1.
 * Since -1 isn't convinient, so use Z for purpose.
 * Conversion:
 *      we can first convert 10's to 3's, then
 *      iterating from rightmost to leftmost.
 *      digit 2 should be turned into Z with adding 1 to next digit
 *      digit 3 should be turned into 0
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// the function doesn't include negative
vector<char> three_base(int n){
    vector<char> ten_to_three;
    if (n==0) ten_to_three.push_back('0');
    while (n>0){
        ten_to_three.push_back(48+(n%3));
        n/=3;
    }
    return ten_to_three;
}

void ternary(int n){
    vector<char> v = three_base(n);
    size_t sz = v.size();
    for (int i=0;i<sz;i++){
        if (v[i]>'1'){
            v[i] = (v[i]=='2'?'Z':'0');
            if (i+1>=sz) v.push_back('1');
            else v[i+1] += 1;
        }
    }
    reverse(v.begin(), v.end());
    for (char i: v) cout <<i;
}

int main(){
    ternary(64); cout <<endl;
    ternary(237); cout <<endl;
}