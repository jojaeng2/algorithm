#include <iostream>
#include <vector>
#define NUM 100001
using namespace std;
int n,m,maxi,mini;
int number[NUM];
int tree[4*NUM][2];

int mininit(int start,int end,int node){
    if(start==end) return tree[node][0] = number[start];
    int mid = (start+end)/2;
    return tree[node][0] = min(mininit(start,mid,node*2),mininit(mid+1,end,node*2+1));
}

int maxinit(int start,int end,int node){
    if(start==end) return tree[node][1] = number[start];
    int mid = (start+end)/2;
    return tree[node][1] = max(maxinit(start,mid,node*2),maxinit(mid+1,end,node*2+1));
}

void sum(int start,int end,int node,int left,int right){
    if(left>end || right<start) return;
    if(left<=start && end<=right){
        mini = min(mini,tree[node][0]);
        maxi = max(maxi,tree[node][1]);
        return;
    }
    int mid = (start+end)/2;
    sum(start,mid,node*2,left,right);
    sum(mid+1,end,node*2+1,left,right);
    return;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> number[i];
    mininit(1,n,1);
    maxinit(1,n,1);
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        maxi = -1;
        mini = 1000000001;
        sum(1,n,1,a,b);
        cout << mini << " " << maxi << '\n';
    }
}