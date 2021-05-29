#include <iostream>
#define int long long int
using namespace std;
int32_t main(){
    int n,h;
    cin>>n>>h;
    int ar[n];
    for (int i = 0; i < n; ++i) {
        cin>>ar[i];
    }
    int sum = 0;
    if (h<n){
        for (int i = 0; i < n; ++i) {
            int s = 0;
            for (int j = i; j < i+h && j<n; ++j) {
                s+=ar[i];
            }
            sum = max(s,sum);
        }
    } else{
        for (int i = 0; i < n; ++i) {
            sum+=ar[i];
        }
    }
    cout<<sum<<"\n";
}