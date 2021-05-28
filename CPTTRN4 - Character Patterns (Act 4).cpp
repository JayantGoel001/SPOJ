#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while (t--){
        int l,c,h,w;
        cin>>l>>c>>h>>w;
        for (int i = 0; i <= c*(w + 1); ++i) {
            cout<<"*";
        }
        cout<<'\n';
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < h; ++j) {
                for (int k = 0; k < c; ++k) {
                    cout<<"*";
                    for (int k2 = 0; k2 < w; ++k2) {
                        cout<<".";
                    }
                }
                cout<<"*\n";
            }
            for (int j = 0; j <= c * (w+1); ++j) {
                cout<<"*";
            }
            cout<<"\n";
        }
        cout<<'\n';
    }
}