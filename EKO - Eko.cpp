#include <iostream>
#define int long long int
using namespace std;
int getRemainingWood(const int *ar,int n,int x){
    int total = 0;
    for (int i = 0; i < n; ++i) {
        if (ar[i]>=x){
            total += (ar[i]-x);
        }
    }
    return total;
}
int minimumHeight(int *ar,int n,int m){
    int low = 0;
    int high = -1;
    for (int i = 0; i < n; ++i) {
        high = max(high,ar[i]);
    }
    int answer = -1;
    while (low<=high){
        int mid = (low+high)/2;
        int remainingWood = getRemainingWood(ar,n,mid);
        if (remainingWood>=m){
            low = mid+1;
            answer = mid;
        } else{
            high = mid-1;
        }
    }
    return answer;
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    int ar[n];
    for (int i = 0; i < n; ++i) {
        cin>>ar[i];
    }
    cout<<minimumHeight(ar,n,m)<<"\n";
}