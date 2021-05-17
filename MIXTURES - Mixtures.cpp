#include <iostream>
#define int long long int
#define INT_MAX2 99999999
using namespace std;
const int mod = 100;

int sum(const int* ar,int x,int y){
    int s = 0;
    for (int i = x; i <=y ; ++i) {
        s= (s+ar[i])%mod;
    }
    return s;
}
int solveMixtures(int *ar,int start,int end,int **dp){
    if (start>=end){
        return 0;
    }
    if (dp[start][end]!=-1){
        return dp[start][end];
    }
    dp[start][end] = INT_MAX2;
    for (int i = start; i <=end ; ++i) {
        dp[start][end] = min(dp[start][end], solveMixtures(ar,start,i,dp) + solveMixtures(ar,i+1,end,dp) + sum(ar,start,i)*sum(ar,i+1,end));
    }
    return dp[start][end];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    while (cin>>n) {
        int ar[n];
        for (int i = 0; i < n; ++i) {
            cin >> ar[i];
        }
        int **dp = new int*[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = new int[n];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = -1;
            }
        }
        cout<<solveMixtures(ar,0,n-1,dp)<<"\n";
    }
}