#include <iostream>
#include <map>
#define int long long int
using namespace std;
int editDistance(const string& str1,const string& str2,int n,int m,map<pair<int,int>,int> &mp){
    if (mp.count(make_pair(n,m))!=0){
        return mp[make_pair(n,m)];
    }
    if (n==0 && m==0){
        mp[make_pair(n,m)] = 0;
        return mp[make_pair(n,m)];
    }
    if (n==0){
        mp[make_pair(n,m)] = m;
        return mp[make_pair(n,m)];
    }
    if (m==0){
        mp[make_pair(n,m)] = n;
        return mp[make_pair(n,m)];
    }
    if (str1[n-1] == str2[m-1]){
        mp[make_pair(n,m)] = editDistance(str1,str2,n-1,m-1,mp);
        return mp[make_pair(n,m)];
    }
    mp[make_pair(n,m)] = 1 + min(editDistance(str1,str2,n-1,m,mp), min(editDistance(str1,str2,n,m-1,mp), editDistance(str1,str2,n-1,m-1,mp)));
    return mp[make_pair(n,m)];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while (t--){
        string str1,str2;
        cin.ignore();
        cin>>str1;
        cin>>str2;
        cin.clear();
        map<pair<int,int>,int> mp;
        cout<<editDistance(str1,str2,str1.length(),str2.length(),mp)<<"\n";
    }
}
