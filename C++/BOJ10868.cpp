#include <iostream>
#include <vector>
#define NUM 100001
using namespace std;
typedef long long ll;
int n,m,mini;
int number[NUM];
int tree[4*NUM];

int init(int start,int end,int node){
    if(start==end) return tree[node] = number[start];
    int mid = (start+end)/2;
    return tree[node] = min(init(start,mid,node*2), init(mid+1,end,node*2+1));
}

void sum(int start,int end,int node,int left,int right){
    if(left>end || right<start) return;
    if(left<=start && end<=right){
        mini = min(mini,tree[node]);
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
    for(int i=1;i<=n;i++){
        cin >> number[i];
    }
    init(1,n,1);
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        mini = 1000000001;
        sum(1,n,1,a,b);
        cout << mini << '\n';
    }
}