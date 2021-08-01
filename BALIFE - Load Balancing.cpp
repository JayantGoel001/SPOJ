#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define int long long int
#define double double_t
#define INF 1e18
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}

const int mod = 1000000000 + 7;

int power(int x, int y, int MOD = mod) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return power((x * x) % MOD, y / 2, MOD) % MOD;
    } else {
        return (x * power((x * x) % MOD, (y - 1) / 2, MOD) % MOD) % MOD;
    }
}

int inverse(int n, int p) {
    return power(n, p - 2, p);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (true) {
        int n;
        cin >> n;
        if (n==-1){
            break;
        }
        int ar[n];
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin>>ar[i];
            sum+=ar[i];
        }
        if (sum%n==0){
            int avg = sum/n;
            int maxi = -1;
            int cumSum[n];
            cumSum[0] = ar[0];
            for (int i = 1; i < n; ++i) {
                cumSum[i] = cumSum[i-1] + ar[i];
            }
            for (int i = 0; i < n; ++i) {
                maxi = max(maxi, abs(cumSum[i] - avg * (i+1)));
            }
            cout<<maxi;
        } else{
            cout<<"-1";
        }
        cout << "\n";
    }
}