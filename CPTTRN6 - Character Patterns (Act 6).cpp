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
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < h; ++j) {
                for (int k = 0; k < c; ++k) {
                    for (int k2 = 0; k2 < w; ++k2) {
                        cout << ".";
                    }
                    cout<<"|";
                }
                for (int k = 0; k < w; ++k) {
                    cout<<".";
                }
                cout<<"\n";
            }
            for (int k = 0; k < c; ++k) {
                for (int k2 = 0; k2 < w; ++k2) {
                    cout << "-";
                }
                cout<<"+";
            }
            for (int k = 0; k < w; ++k) {
                cout<<"-";
            }
            cout<<"\n";
        }
        for (int i = 0; i < h; ++i) {
            for (int k = 0; k < c; ++k) {
                for (int k2 = 0; k2 < w; ++k2) {
                    cout << ".";
                }
                cout << "|";
            }
            for (int k = 0; k < w; ++k) {
                cout << ".";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
}