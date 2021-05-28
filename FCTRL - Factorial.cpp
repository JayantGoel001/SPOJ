#include <iostream>
#include <valarray>

#define int long long int
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int sum = 0;
        int i = 1;
        while (n!=0){
            sum += n/(int)pow(5,i);
            n/=5;
        }
        cout<<sum<<'\n';
    }
}