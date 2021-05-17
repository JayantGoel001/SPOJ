#include <iostream>
#define int long long int
using namespace std;
int32_t main(){
    int n,s;
    cin>>s>>n;
    int weights[n];
    int value[n];
    for (int i = 0; i < n; ++i) {
        cin>>weights[i]>>value[i];
    }
    int **dp = new int*[n+1];
    for (int i = 0; i <= n; ++i) {
        dp[i] = new int[s+1];
    }
    for (int i = 0; i <=n; ++i) {
        for (int j = 0; j <=s; ++j) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= s; ++j) {
            if (i==0 || j==0){
                dp[i][j] = 0;
            } else if (weights[i-1]<=j){
                dp[i][j] = max(dp[i-1][j],value[i-1]+dp[i-1][j-weights[i-1]]);
            } else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][s]<<"\n";
}