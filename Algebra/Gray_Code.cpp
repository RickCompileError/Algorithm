/* 
 * Gray code is a binary numeral system where
 * two successive values differ in only one bit
 */
#include <iostream>
#include <bitset>
#include <string>
#include <vector>

using namespace std;

void generate_by_reverse(int n){
    if (n<=0) return;
    vector<string> gray;
    gray.push_back("0");
    gray.push_back("1");
    for (int i=2;i<(1<<n);i=i<<1){
        size_t sz = gray.size();
        for (int j=sz-1;j>=0;j--){
            gray.push_back("1"+gray[j]);
            gray[j] = "0"+gray[j];
        }
    }
    // for (string i: gray) cout <<i <<endl;
}

vector<string> generate_by_recursive(int n){
    if (n==0) return {"0"};
    if (n==1) return {"0","1"};
    vector<string> recur = generate_by_recursive(n-1);
    vector<string> extend;
    size_t sz = recur.size();
    for (int i=0;i<sz;i++) extend.push_back("0"+recur[i]);
    for (int i=sz-1;i>=0;i--) extend.push_back("1"+recur[i]);
    return extend;
}

void generate_by_bitset(int n){
    vector<string> gray;
    for (int i=0;i<(1<<n);i++){
        int g = i ^ (i>>1);
        bitset<32> b(g);
        gray.push_back(b.to_string().substr(32-n));
    }
    // for (string i: gray) cout <<i <<endl;
}

void gray_inverse_to_number(string g){
    bitset<32> b(g);
    int gray = b.to_ulong();
    int num = 0;
    for (;gray;gray>>=1) num ^= gray;
    cout <<g <<" inverse to " <<num <<endl;
}

int main(){
    generate_by_reverse(3);

    vector<string> gray;
    gray = generate_by_recursive(3);
    // for (string i: gray) cout <<i <<endl;
    
    generate_by_bitset(3);

    gray_inverse_to_number("110");
}