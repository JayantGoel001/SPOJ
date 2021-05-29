#include <iostream>
#include <cmath>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while (t--){
        int xo1,yo1,r1,xo2,yo2,r2;
        cin>>xo1>>yo1>>r1>>xo2>>yo2>>r2;
        float distance = sqrt(pow((xo1 - xo2),2) + pow((yo1 - yo2),2));
        if (distance == abs(r1-r2)){
            cout<<"E\n";
        } else if (distance< abs(r1-r2)){
            cout<<"I\n";
        } else{
            cout<<"O\n";
        }
    }
}