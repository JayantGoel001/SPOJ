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

int power(int x, int y) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return power((x * x), y / 2);
    } else {
        return (x * power((x * x), (y - 1) / 2));
    }
}

int inverse(int n, int p) {
    return power(n, p - 2);
}
vector<int> prime;
int TOT = 1e5 + 8;
void sieve(){
    bool isPrime[TOT];
    for (int i = 0; i <=TOT; ++i) {
        isPrime[i] = i%2;
    }
    isPrime[1]= false;
    isPrime[2] = true;
    for (int i = 2; i*i <=TOT ; ++i) {
        if (isPrime[i]){
            for (int j = i*i; j <=TOT ; j+=2*i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 0; i <=TOT; ++i) {
        if (isPrime[i]){
            prime.push_back(i);
        }
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
        int n;
        cin >> n;
        int f = n;
        int output = 1;
        for (int i = 0; i < prime.size() && prime[i]*prime[i]<=n; ++i) {
            if (n%prime[i]==0){
                int count = 0;
                while (n%prime[i]==0){
                    n/=prime[i];
                    count++;
                }
                output *= ((power(prime[i],count+1) - 1)/(prime[i]-1));
            }
        }
        if (n!=1){
            output *= (n+1);
        }
        cout<<output-f;
        cout << "\n";
    }
}