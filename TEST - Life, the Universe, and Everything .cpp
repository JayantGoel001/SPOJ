#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while (cin>>n){
        if (n==42){
            break;
        }
        cout<<n<<'\n';
    }
}