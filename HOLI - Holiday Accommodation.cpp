#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define int long long int
#define INF 1e18
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}

int power(int x, int y, int MOD = INF) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return power((x * x) % MOD, y / 2) % MOD;
    } else {
        return (x * power((x * x) % MOD, (y - 1) / 2) % MOD) % MOD;
    }
}
int answer = 0;
int V;
int DFS(vector<pair<int,int>> *adj,bool *isVisited,vector<int> &count,int x){
    isVisited[x] = true;
    count[x] = 1;
    for (auto it:adj[x]) {
        if (!isVisited[it.first]){
            count[x] += DFS(adj,isVisited,count,it.first);
            answer += 2 * min(count[it.first],V-count[it.first]) * it.second;
        }
    }
    return count[x];
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int n;
        cin >> n;
        V = n;
        vector<pair<int,int>> adj[n];
        for (int i = 0; i < n-1; ++i) {
            int x,y,z;
            cin>>x>>y>>z;
            x--;
            y--;
            adj[x].emplace_back(y,z);
            adj[y].emplace_back(x,z);
        }
        bool isVisited[n];
        for (int i = 0; i < n; ++i) {
            isVisited[i] = false;
        }
        vector<int> count(n,0);
        DFS(adj,isVisited,count,0);
        cout<<"Case #"<<_+1<<": "<<answer;
        answer = 0;
        cout << "\n";
    }
}