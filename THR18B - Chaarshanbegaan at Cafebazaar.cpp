#include <iostream>
#include <cmath>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    int score = 0;
    while (t--){
        int x,y;
        cin>>x>>y;
        float d = sqrt(x*x + y*y);
        if (d<=10){
            score+=10;
        } else if(d<=30){
            score+=9;
        } else if (d<=50){
            score+=8;
        } else if (d<=70){
            score+=7;
        } else if (d<=90){
            score+=6;
        } else if (d<=110){
            score+=5;
        } else if (d<=130){
            score+=4;
        } else if (d<=150){
            score+=3;
        } else if (d<=170){
            score+=2;
        } else if(d<=190){
            score+=1;
        } else{
            score+=0;
        }
    }
    cout<<score<<"\n";
}