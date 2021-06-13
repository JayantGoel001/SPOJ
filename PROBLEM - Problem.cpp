#include<bits/stdc++.h>
#define int long long int
#define INF 1e18
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin>>t;
    map<char,int> mp;
    mp['0'] = 1;
    mp['1'] = 0;
    mp['2'] = 0;
    mp['3'] = 0;
    mp['4'] = 0;
    mp['5'] = 0;
    mp['6'] = 1;
    mp['7'] = 0;
    mp['8'] = 2;
    mp['9'] = 1;
    while(t--){
        string str;
        cin>>str;
        int sum = 0;
        for (int i = 0; i < str.length(); ++i) {
            sum+=mp[str[i]];
        }
        cout<<sum<<"\n";
    }
}