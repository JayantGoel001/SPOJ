#include<bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    while(t--){
        int n;
        cin>>n;
        int fact = 1;
        for (int i = 1; i <= n; ++i) {
            fact*=i;
        }
        cout<<fixed<<setprecision(0)<<fact + pow(2,n) - n<<"\n";
    }
}