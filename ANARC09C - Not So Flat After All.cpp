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
map<int,int> ar[TOT+1];
void sieve(){
    int isPrime[TOT + 1];
    for (int i = 0; i <=TOT; ++i) {
        isPrime[i] = i%2;
    }
    isPrime[1] = false;
    isPrime[2] = true;
    for (int i = 3; i*i <=TOT ; i+=2) {
        if(isPrime[i]){
            for (int j = i*i; j <=TOT ; j+=i) {
                isPrime[j] = false;
            }
        }
    }
    vector<int> prime;
    for (int i = 0; i <=TOT; ++i) {
        if(isPrime[i]){
            prime.push_back(i);
        }
    }
    for (int i = 2; i <=TOT; ++i) {
        int x = i;
        for (int j = 0; j <prime.size() && prime[j] * prime[j]<=x; ++j) {
            while (x%prime[j]==0){
                ar[i][prime[j]]++;
                x/=prime[j];
            }
        }
        if(x>1){
            ar[i][x]++;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    sieve();
    int i = 1;
    while (true) {
        int a,b;
        cin >> a>>b;
        if(a==0 && b==0){
            break;
        }
        map<int,int> mp1 = ar[a];
        map<int,int> mp2 = ar[b];
        set<int> s;
        for(auto it: mp1){
            s.insert(it.first);
        }
        for (auto it:mp2) {
            s.insert(it.first);
        }

        int d = 0;
        for(auto it:s){
            d += abs(mp1[it] - mp2[it]);
        }
        cout<<i++<<". "<<s.size()<<":"<<d;
        cout << "\n";
    }
}