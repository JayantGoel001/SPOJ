#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while (t--){
        int n,x,y;
        cin>>n>>x>>y;
        for (int i = 1; i < n; ++i) {
            if (i%x==0 && i%y!=0){
                cout<<i<<" ";
            }
        }
        cout<<'\n';
    }
}