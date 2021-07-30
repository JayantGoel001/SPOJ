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
const int TOT = 1000000;
int G[TOT+1];
void sieve(){
    int phi[TOT+1];
    for (int i = 0; i <=TOT; ++i) {
        phi[i] = i;
    }
    for (int i = 2 ;i <=TOT; ++i) {
        if(phi[i]==i){
            for (int j = i; j <=TOT ; j+=i) {
                phi[j] = (phi[j]/i) * (i-1);
            }
        }
    }
    for (int i = 1; i <=TOT; ++i) {
        G[i] = 0;
    }
    for (int i = 1; i <=TOT; ++i) {
        for (int j = 2*i; j <=TOT; j+=i) {
            G[j] += i * phi[j/i];
        }
    }
    for (int i = 1; i <=TOT; i++) {
        G[i] += G[i-1];
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    sieve();
    while (true) {
        int n;
        cin >> n;
        if(n==0){
            break;
        }
        cout<<G[n];
        cout << "\n";
    }
}