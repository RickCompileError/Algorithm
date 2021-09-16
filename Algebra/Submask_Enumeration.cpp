/* 
From wiki,
    bitmask is data that is used for bitwise operation.
    Using a mask, multiple bits in a byte, nibble, word etc.
    can be set either on, off or inverted from on to off (vice versa).
    An additional use and meaning of Masking involves predication in Vector processing.
*/

#include <iostream>

using namespace std;

void while_version(int m){
    int s = m;
    while (s>0){
        cout <<s <<' ';
        s = (s-1) & m;
    }
    cout <<endl;
}

void for_version(int m){
    for (int s=m;s;s=(s-1)&m) cout <<s <<' ';
    cout <<endl;
}

void iteration_all(int n){
    for (int m=0;m<(1<<3);m++){
        cout <<m <<": ";
        for (int s=m;s;s=(s-1)&m) cout <<s <<' ';
        cout <<endl;
    }
}

int main(){
    while_version(5);
    for_version(5);
    iteration_all(2);
}