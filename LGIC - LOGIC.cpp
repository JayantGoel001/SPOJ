#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define int long long int
#define INF 1e18
using namespace __gnu_pbds;
using namespace std;
typedef tree<pair<int, int>, null_type, less<pair<int , int>>, rb_tree_tag, tree_order_statistics_node_update > pbdS;
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