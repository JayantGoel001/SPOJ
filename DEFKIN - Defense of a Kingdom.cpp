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
    int t = 1;
    cin >> t;
    while (t--) {
        int w,h,n;
        cin >> w>>h>>n;
        vector<int> x(n);
        vector<int> y(n);
        for (int i = 0; i < n; ++i) {
            cin>>x[i]>>y[i];
        }
        x.push_back(w+1);
        y.push_back(h+1);
        sort(x.begin(),  x.end());
        sort(y.begin(),  y.end());
        int maxX = x[0]-1;
        int maxY = y[0]-1;
        for (int i = 0; i < n; ++i) {
            maxX = max(maxX, x[i+1] - x[i] - 1);
            maxY = max(maxY, y[i+1] - y[i] - 1);
        }
        cout<<maxX * maxY;
        cout << "\n";
    }
}