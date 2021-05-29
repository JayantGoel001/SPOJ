#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int s[n];
    for (int i = 0; i < n; ++i) {
        cin>>s[i];
    }
    int m;
    cin>>m;
    int q[m];
    for (int i = 0; i < m; ++i) {
        cin>>q[i];
    }
    for (int i = 0; i < min(m, n); ++i) {
        if (q[i]==s[i]){
            cout<<i+1<<" ";
        }
    }
}
