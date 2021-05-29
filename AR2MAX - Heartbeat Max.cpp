#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int maxi = -999999;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            cin>>x;
            maxi = max(maxi,x);
        }
    }
    cout<<maxi<<"\n";
}