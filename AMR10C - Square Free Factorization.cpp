#include<bits/stdc++.h>
using namespace std;
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
const int N = 1000000 + 1;
void sieve() {
    bool isPrime[N + 1];
    for (int i = 0; i <= N; ++i) {
        isPrime[i] = i % 2;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    isPrime[2] = true;
    for (int i = 3; i * i <= N; i += 2) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += 2 * i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= N; ++i) {
        if (isPrime[i]) {
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
        map<int,int> mp;
        for(int i = 0;prime[i]*prime[i]<=n;i++){
            while(n%prime[i]==0){
                mp[prime[i]]++;
                n/=prime[i];
            }
        }
        if (n>1){
            mp[n]++;
        }
        int maxi = -1;
        for(auto it:mp){
            maxi = max(maxi,it.second);
        }
        cout<<maxi;
        cout << "\n";
    }
}