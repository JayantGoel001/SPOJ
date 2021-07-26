#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define int unsigned long long int
#define double double_t
#define INF 1e18
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}

const int mod = 1e9 + 7;

int power(int x, int y, int MOD=mod) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return power((x * x) % MOD, y / 2, MOD) % MOD;
    } else {
        return (x * power((x * x) % MOD, (y - 1) / 2, MOD) % MOD) % MOD;
    }
}
map<int,int> mp;
int calculateFibonacci(int n,int MOD = mod){
    if (n==0){
        return 0;
    }
    if (n==1 || n==2){
        return 1;
    }
    if (mp.count(n)){
        return mp[n]%MOD;
    }
    if (n%2==0){
        int x1 = calculateFibonacci(n/2-1)%MOD;
        int x2 = calculateFibonacci(n/2)%MOD;
        mp[n] = (((2 * x1)%MOD + x2 )%MOD * x2)%MOD;
        return mp[n]%MOD;
    } else{
        int x1 = calculateFibonacci((n+1)/2)%MOD;
        int x2 = calculateFibonacci((n-1)/2)%MOD;
        mp[n] = ((x1 * x1)%MOD + (x2 * x2)%MOD)%MOD;
        return mp[n]%MOD;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n==0){
            cout<<"0";
        } else if(n==1){
            cout<<"2";
        } else{
            n = n+3;
            cout<<calculateFibonacci(n)%mod;
        }
        cout << "\n";
    }
}