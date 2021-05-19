#include <iostream>
#include <algorithm>
#define int long long int
using namespace std;
int getCows(const int *ar,int n,int x){
    int prev = ar[0];
    int cows = 1;
    for (int i = 1; i < n; ++i) {
        if ((ar[i]-prev)>=x){
            cows++;
            prev = ar[i];
        }
    }
    return cows;
}
int minimumDistance(int *ar,int n,int c){
    int low = 0;
    int high = ar[n-1];
    int maxi=0;
    while (low<=high){
        int mid = (low+high)/2;
        int numberOfCows = getCows(ar,n,mid);
        if (numberOfCows>=c){
            maxi= mid;
            low = mid+1;
        } else{
            high = mid-1;
        }
    }
    return maxi;
}
int32_t main(){
    int t;
    cin>>t;
    while (t--){
        int n,c;
        cin>>n>>c;
        int *ar = new int[n];
        for (int i = 0; i < n; ++i) {
            cin>>ar[i];
        }
        sort(ar,ar+n);
        cout<<minimumDistance(ar,n,c)<<"\n";
    }
}