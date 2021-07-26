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

const int mod = 109546051211;

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
    while (t--) {
        int n;
        cin >> n;
        int rem1 = 1;
        int rem2 = 1;
        int fact1 = 1;
        int fact2 = 1;
        int p1 = 186583;
        int p2 = 587117;
        for (int i = 2; i <=n ; ++i) {
            fact1 = (fact1 * i)%p1;
            fact2 = (fact2 * i)%p2;
            rem1 = (rem1 * fact1)%p1;
            rem2 = (rem2 * fact2)%p2;
        }
        int prod = p1 * p2;
        int pp1 = prod/p1;
        int pp2 = prod/p2;
        int output = ( pp1 * rem1 * inverse(pp1,p1) + pp2 * rem2 * inverse(pp2,p2) )%mod;
        cout<<output;
        cout << "\n";
    }
}