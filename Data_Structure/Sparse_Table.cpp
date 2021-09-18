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

#include <iostream>

using namespace std;

int main(){

}