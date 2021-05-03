#include <iostream>
#include <map>
using namespace std;

int countMinMoves(int n,int *dp){
    if (n<=1){
        dp[n] = 0;
        return 0;
    }
    if (dp[n]!=-1){
        return dp[n];
    }
    int sub = countMinMoves(n-1,dp);
    if (n%2==0){
        sub = min(sub,countMinMoves(n/2,dp));
    }
    if (n%3==0){
        sub = min(sub,countMinMoves(n/3,dp));
    }
    dp[n] = 1+ sub;
    return dp[n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    int i=1;
    int TOT = 20000001;
    int *dp = new int [TOT];
    for (int j=0; j<=TOT; j++){
        dp[j] = -1;
    }
    countMinMoves(TOT,dp);
    while (t--) {
        int n;
        cin >> n;
        cout <<"Case "<<i<<": "<<dp[n]<<"\n";
        i++;
    }
}