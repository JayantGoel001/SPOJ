#include<bits/stdc++.h>
using namespace std;

const int TOT = 1000000;
int ar[11][TOT+1];
void sieve(){
    int numberOfFactors[TOT+1];
    for (int i = 0; i <=TOT; ++i) {
        numberOfFactors[i] = 0;
    }
    for (int i = 2; i <=TOT; ++i) {
        if(numberOfFactors[i]==0){
            for (int j = i; j <=TOT ; j+=i) {
                numberOfFactors[j]++;
            }
        }
    }
    for (int i = 0; i <= 10; ++i) {
        for (int j = 1; j <=TOT; ++j) {
            ar[i][j] = ar[i][j-1];
            if(numberOfFactors[j]==i){
                ar[i][j]++;
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    sieve();
    while (t--) {
        int a,b,n;
        cin >> a>>b>>n;
        cout<<ar[n][b] - ar[n][a-1];
        cout << "\n";
    }
}