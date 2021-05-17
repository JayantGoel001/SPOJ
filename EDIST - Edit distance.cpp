#include <iostream>
#define int long long int
using namespace std;
int editDistance(const string& str1,const string& str2,int n,int m,int **dp){
    if (dp[n][m]!=-1){
        return dp[n][m];
    }
    if (n==0 && m==0){
        dp[n][m] = 0;
        return dp[n][m];
    }
    if (n==0){
        dp[n][m] = m;
        return dp[n][m];
    }
    if (m==0){
        dp[n][m] = n;
        return dp[n][m];
    }
    if (str1[n-1] == str2[m-1]){
        dp[n][m] = editDistance(str1,str2,n-1,m-1,dp);
        return dp[n][m];
    }
    dp[n][m] = 1 + min(editDistance(str1,str2,n-1,m,dp), min(editDistance(str1,str2,n,m-1,dp), editDistance(str1,str2,n-1,m-1,dp)));
    return dp[n][m];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while (t--){
        string str1,str2;
        cin.ignore();
        cin>>str1;
        cin>>str2;
        cin.clear();
        int n= str1.length();
        int m =str2.length();
        int **dp = new int*[n+1];
        for (int i = 0; i <=n; ++i) {
            dp[i] = new int[m+1];
        }
        for (int i = 0; i <=n; ++i) {
            for (int j = 0; j <=m; ++j) {
                dp[i][j] =-1;
            }
        }
        cout<<editDistance(str1,str2,n,m,dp)<<"\n";
    }
}
