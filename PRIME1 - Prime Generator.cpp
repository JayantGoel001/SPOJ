#include <bits/stdc++.h>
#define int long long int
using namespace std;
void sieve(vector<int> &prime,int N){
    int limit = (int)sqrt(N);
    bool isPrime[limit+1];
    for (int i = 0; i <=limit; ++i) {
        isPrime[i] = i%2;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    isPrime[2] = true;
    for (int i = 3; i*i <=limit; i+=2) {
        if(isPrime[i]) {
            for (int j = i * i; j <= limit; j += 2 * i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <=limit; ++i) {
        if (isPrime[i]){
            prime.push_back(i);
        }
    }
}
void segmentedSieve(int low,int high){
    vector<int> prime;
    sieve(prime,high);
    int segmentedLimit = high-low;
    bool isSegmentedPrime[segmentedLimit+1];
    for (int i = 0; i <= segmentedLimit; ++i) {
        isSegmentedPrime[i] = true;
    }
    for (int i = 0; i < prime.size(); ++i) {
        int j = low;
        while (j<=high){
            if (j%prime[i]==0 && j!=prime[i]) {
                isSegmentedPrime[j - low] = false;
            }
            if (j%prime[i]==0){
                j+=prime[i];
            } else{
                j++;
            }
        }
    }
    for (int i = low; i <= high; ++i) {
        if (isSegmentedPrime[i-low] && i!=1){
            cout<<i<<"\n";
        }
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while (t--){
        int m,n;
        cin>>m>>n;
        segmentedSieve(m,n);
        cout<<"\n";
    }
}