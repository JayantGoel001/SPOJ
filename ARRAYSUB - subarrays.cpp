#include<iostream>
#include <deque>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ar[n];
    for (int i = 0; i < n; ++i) {
        cin>>ar[i];
    }
    int k;
    cin>>k;
    deque<int> d(k);
    for(int i=0;i<n;i++){
        if(i>=k){
            cout << ar[d.front()] << " ";
            while(!d.empty() && d.front() <= i - k){
                d.pop_front();
            }
        }
        while(!d.empty() && ar[i] >= ar[d.back()]){
            d.pop_back();
        }
        d.push_back(i);
    }
    cout<<ar[d.front()];
}