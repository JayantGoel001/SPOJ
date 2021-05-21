#include <iostream>
#include <valarray>
using namespace std;
int arr[1000005],freq[1000005],block;
int answer;
class Query{
public:
    int first,second,index;
};
bool cmp(Query a, Query b){
    if(a.first/block!=b.first/block) {
        return a.first < b.first;
    }
    return a.second<b.second;
}
void remove(int index){
    freq[arr[index]]--;
    if(freq[arr[index]]==0){
        answer--;
    }
}
void add(int index){
    freq[arr[index]]++;
    if(freq[arr[index]]==1){
        answer++;
    }
}
int main() {
    int i,q,n,x=0,y=0;
    scanf("%d",&n);
    block=sqrt(n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&q);
    Query query[q];
    int ans[q];
    i=0;
    while(i<q){
        scanf("%d %d",&x,&y);
        x--;
        y--;
        query[i].first=x;
        query[i].second=y;
        query[i].index=i;
        i++;
    }
    sort(query, query + q, cmp);
    int currentL=0,currentR=0;
    for(i=0;i<q;i++){
        while(query[i].first > currentL){
            remove(currentL);
            currentL++;
        }
        while(query[i].first < currentL){
            currentL--;
            add(currentL);
        }
        while(currentR > query[i].second + 1){
            currentR--;
            remove(currentR);
        }
        while(query[i].second >= currentR){
            add(currentR);
            currentR++;
        }
        ans[query[i].index]=answer;
    }
    for(i=0;i<q;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}