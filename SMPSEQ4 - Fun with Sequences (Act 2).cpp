#include <iostream>
#include <map>
using namespace std;
int main(){
    int n;
    cin>>n;
    int s[n];
    for (int i = 0; i < n; ++i) {
        cin>>s[i];
    }
    int m;
    cin>>m;
    int q[m];
    map<int,bool> mp;
    for (int i = 0; i < m; ++i) {
        cin>>q[i];
        mp[q[i]] = true;
    }
    for (int i = 0; i < n; ++i) {
        if (mp.count(s[i])!=0){
            cout<<s[i]<<" ";
        }
    }
}
