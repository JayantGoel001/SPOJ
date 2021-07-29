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
const int TOT = 100000000;
int ar[TOT+1];
void sieve(){
    bool isPrime[TOT+1];
    for (int i = 0; i <=TOT; ++i) {
        isPrime[i]= i%2;
    }
    isPrime[1] = false;
    isPrime[2] = true;
    for (int i = 3; i*i <=TOT ; i+=2) {
        if(isPrime[i]){
            for (int j = i*i; j <=TOT ; j += 2 * i) {
                isPrime[j] = false;
            }
        }
    }
    ar[1] = 0;
    for (int i = 2; i <=TOT ; ++i) {
        if(isPrime[i]){
            ar[i] = ar[i-1] + 1;
        } else{
            ar[i] = ar[i-1];
        }
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
        cout<<fixed<<setprecision(1)<<(abs(ar[n] - n/ log(n))/ar[n])*100;
        cout << "\n";
    }
}