#include <iostream>
#include <map>
#define int long long int
using namespace std;
int LCS(const string& str1,const string& str2,int n,int m,map<pair<int,int>,int> &mp){
    if (mp.count(make_pair(n,m))!=0){
        return mp[make_pair(n,m)];
    }
    if (n==0 || m==0){
        mp[make_pair(n,m)] = 0;
        return mp[make_pair(n,m)];
    }
    if (str1[n-1]==str2[m-1]){
        mp[make_pair(n,m)] =  1+ LCS(str1,str2,n-1,m-1,mp);
        return mp[make_pair(n,m)];
    }
    mp[make_pair(n,m)] = max(LCS(str1,str2,n-1,m,mp), LCS(str1,str2,n,m-1,mp));
    return mp[make_pair(n,m)];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string str1,str2;
    while (cin>>str1>>str2) {
        map<pair<int, int>, int> mp;
        int i = str1.length();
        int j = str2.length();
        int l = LCS(str1,str2,i,j,mp);
        string lcs;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                lcs = str1[i-1] + lcs;
                i--;
                j--;
            } else if (mp[make_pair(i - 1, j)] > mp[make_pair(i, j - 1)]) {
                i--;
            } else {
                j--;
            }
        }
        i = str1.length();
        j = str2.length();
        string non_lcs;
        int k = lcs.length();
        while (i>0 || j>0){
            if (k>0) {
                while (i > 0 && str1[i - 1] != lcs[k - 1]) {
                    non_lcs = str1[i - 1] + non_lcs;
                    i--;
                }
                while (j > 0 && str2[j - 1] != lcs[k - 1]) {
                    non_lcs = str2[j - 1] + non_lcs;
                    j--;
                }
                non_lcs = lcs[--k] + non_lcs;
                i--;
                j--;
            } else{
                while (i>0){
                    non_lcs = str1[--i] + non_lcs;
                }
                while (j>0){
                    non_lcs = str2[--j] + non_lcs;
                }
            }
        }
        cout<<non_lcs<<"\n";
    }
}