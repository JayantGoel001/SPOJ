#include <iostream>
#include <vector>
#include <algorithm>
#define INT_MIN -999999
#define int long long int
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int ar1[n],ar2[n];
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            cin>>ar1[i];
        }
        for(int i=0;i<n;i++){
            cin>>ar2[i];
        }
        for (int i = 0; i < n; ++i) {
            vp.emplace_back(ar1[i],ar2[i]);
        }
        sort(vp.begin(), vp.end());
        int *lis = new int[n];
        for (int i = 0; i < n; ++i) {
            lis[i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (vp[i].second>=vp[j].second && lis[i]<lis[j]+1){
                    lis[i] = lis[j]+1;
                }
            }
        }
        int res = INT_MIN;
        for (int i = 0; i < n; ++i) {
            res = max(res,lis[i]);
        }
        cout<<res<<"\n";
    }
}