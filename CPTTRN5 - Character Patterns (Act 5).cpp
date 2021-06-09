#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while (t--){
        int l,c,s;
        cin>>l>>c>>s;
        for (int i = 0; i <=l * ( s + 1 ); ++i) {
            for (int j = 0; j <=  c * (s + 1); ++j) {
                if (i%(s+1) ==0 || j%(s+1) == 0){
                    cout<<"*";
                } else if ((i/(s+1) + j/(s+1))%2==0){
                    if (i%(s+1) == j%(s+1)) {
                        cout << "\\";
                    } else{
                        cout<<".";
                    }
                } else{
                    if (i%(s+1) + j%(s+1) == (s+1)) {
                        cout << "/";
                    } else{
                        cout<<".";
                    }
                }
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
}