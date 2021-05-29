#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            cin>>x;
            sum+=x;
        }
    }
    cout<<sum<<"\n";
}