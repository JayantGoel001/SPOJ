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
vector<int> prime;
void sieve(){
    int TOT = 50;
    bool isPrime[TOT+1];
    for (int i = 0; i <=TOT; ++i) {
        isPrime[i] = true;
    }
    for (int i = 2; i*i <=TOT; ++i) {
        if (isPrime[i]){
            for (int j = i*i; j <=TOT; j+=i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <=TOT ; ++i) {
        if (isPrime[i]){
            prime.push_back(i);
        }
    }
}
int nCr(int n,int r,int m){
    int C[r+1];
    for (int i = 0; i <=r; ++i) {
        C[i] = 0;
    }
    C[0] = 1;
    for (int i = 1; i <=n; ++i) {
        for (int j = min(i,r); j >0 ; --j) {
            C[j] = (C[j] + C[j-1])%m;
        }
    }
    return C[r];
}
int LucasApproach(int n,int r,int m){
    if (r==0){
        return 1;
    } else{
        return (LucasApproach(n/m,r/m,m) * nCr(n%m,r%m,m))%m;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    sieve();
    while (t--) {
        int n,r,m;
        cin >> n>>r>>m;
        vector<int> factors;
        for (int i = 0; i < prime.size() && m!=1; ++i) {
            if (m%prime[i]==0){
                factors.push_back(prime[i]);
                m/=prime[i];
            }
        }
        if (m!=1){
            factors.push_back(m);
        }
        vector<int> rem;
        for (int i = 0; i < factors.size(); ++i) {
            rem.push_back(LucasApproach(n,r,factors[i]));
        }
        int prod = 1;
        for (int i = 0; i < factors.size(); ++i) {
            prod *= factors[i];
        }
        int output = 0;
        for (int i = 0; i < factors.size(); ++i) {
            output =  (output + ((prod/factors[i]) * rem[i] * inverse(prod/factors[i],factors[i]))%prod)%prod;
        }
        cout<<output;
        cout << "\n";
    }
}