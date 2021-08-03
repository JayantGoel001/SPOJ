#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define int long long int
#define pii pair<int,int>
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
        int n;
        cin >> n;
        pii ar[n+1];
        for (int i = 0; i <n; ++i) {
            cin>>ar[i].first>>ar[i].second;
        }
        int L,P;
        cin>>L>>P;
        for (int i = 0; i <n; ++i) {
            ar[i].first = L - ar[i].first;
        }
        sort(ar,ar+n);
        int start = P;
        int count = 0;
        priority_queue<int> pq;
        vector<int> visited(n, false);
        while (start<L){
            for (int i = 0; i < n; ++i) {
                if (ar[i].first<=start && !visited[i]){
                    pq.push(ar[i].second);
                    visited[i] = true;
                }
            }
            if (pq.empty()){
                count = -1;
                break;
            }
            start += pq.top();
            pq.pop();
            count++;
        }
        cout<<count;
        cout << "\n";
    }
}