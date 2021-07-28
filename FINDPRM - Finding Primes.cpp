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
const int TOT = 10000001;
int prime[TOT+1];
bool isPrime1[TOT+1];
void sieve(){
    for (int i = 0; i <= TOT; ++i) {
        isPrime1[i] = true;
    }
    for (int i = 3; i*i <=TOT; i+=2) {
        if (isPrime1[i]){
            for (int j = i*i; j <=TOT; j+=2*i) {
                isPrime1[j] = false;
            }
        }
    }
    prime[2] = 1;
    for (int i = 3; i <=TOT; ++i) {
        if (isPrime1[i] && i%2!=0){
            prime[i] = prime[i-1] + 1;
        } else{
            prime[i] = prime[i-1];
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    sieve();
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        cout<<prime[n] - prime[n/2]<<"\n";
    }
}