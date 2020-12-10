#include<iostream>
#include <deque>
#include <algorithm>

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
    deque<int> Q(k);
    for(int i=0;i<n;i++){
        if(i>=k){
            cout<<ar[Q.front()]<<" ";
            while(!Q.empty() && Q.front()<=i-k){
                Q.pop_front();
            }
        }
        while(!Q.empty() && ar[i]>=ar[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
    }
    cout<<ar[Q.front()];
}