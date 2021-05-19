#include<iostream>
#include <valarray>
#define int long long int
using namespace std;
int getRequiredPrata(const int *ar,int n,int x){
    int total = 0;
    for (int i = 0; i < n; ++i) {
        total += (sqrt((ar[i]*ar[i])+ (8*ar[i]*x)) - ar[i])/(2*ar[i]);
    }
    return total;
}
int getMinimumTime(int *ar,int n,int p){
    int low = 1;
    int high = 5*p*(p+1);
    while (low<=high){
        int mid = (low + high)/2;
        int requiredPrata = getRequiredPrata(ar,n,mid);
        if (requiredPrata<p){
            low = mid + 1;
        } else{
            high = mid-1;
        }
    }
    return low;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while (t--){
        int p;
        cin>>p;
        int n;
        cin>>n;
        int ar[n];
        for (int i = 0; i < n; ++i) {
            cin>>ar[i];
        }
        cout<<getMinimumTime(ar,n,p)<<'\n';
    }
}