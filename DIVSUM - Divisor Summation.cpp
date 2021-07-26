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

const int mod = 1e9 + 7;

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
const int TOT = 500000;
int divSum[TOT+1];
void calculateDIVSUM(){
    for (int i = 0; i <=TOT; ++i) {
        divSum[i] = 0;
    }
    for (int i = 1; i <=TOT; ++i) {
        for (int j = 2 * i; j <=TOT; j+=i) {
            divSum[j]+=i;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    calculateDIVSUM();
    while (t--) {
        int n;
        cin >> n;
        cout<<divSum[n];
        cout << "\n";
    }
}