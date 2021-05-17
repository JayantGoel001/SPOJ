#include <iostream>
#define int long long int
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int TOT = 1000000000;
    bool isPrime[TOT+1];
    for (int i = 0; i <=TOT; ++i) {
        isPrime[i] = true;
    }
    isPrime[1] = false;
    for (int i = 2; i*i <=TOT ; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= TOT; j += i) {
                isPrime[j] = false;
            }
        }
    }
    int t;
    cin>>t;
    while (t--){
        int m,n;
        cin>>m>>n;
        for (int i = m; i <=n; ++i) {
            if (isPrime[i]){
                cout<<i<<"\n";
            }
        }
        cout<<"\n";
    }
}