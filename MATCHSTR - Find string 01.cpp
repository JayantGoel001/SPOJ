#include <iostream>
using namespace std;
int main(){
    string s,t;
    cin>>s;
    cin>>t;
    int count = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (i+t.length()<s.length() && s.substr(i,t.length())==t){
            count++;
        }
    }
    cout<<count<<"\n";
}