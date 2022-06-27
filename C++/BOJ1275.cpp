#include <iostream>
#define NUM 100001
using namespace std;
typedef long long ll;
int n,m;
ll number[NUM];
ll tree[4*NUM];

ll init(int start,int end,int node){
    if(start==end) return tree[node] = number[start];
    int mid = (start+end)/2;
    return tree[node] = init(start,mid,node*2) + init(mid+1,end,node*2+1);
}

ll sum(int start,int end,int node,int left,int right){
    if(left>end || right<start) return 0;
    if(left<=start && end<=right) return tree[node];
    int mid = (start+end)/2;
    return sum(start,mid,node*2,left,right) + sum(mid+1,end,node*2+1,left,right);
}

void update(int start,int end,int node,int index,ll dif){
    if(index<start || index > end) return;
    tree[node] -= number[index];
    tree[node] += dif;
    if(start==end) return;
    int mid = (start+end)/2;
    update(start,mid,node*2,index,dif);
    update(mid+1,end,node*2+1,index,dif);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> number[i];
    init(1,n,1);
    for(int i=0;i<m;i++){
        int a,b,c;
        ll d;
        cin >> a >> b >> c >> d;
        if(a>b){
            int temp = a;
            a = b;
            b = temp;
        }
        cout << sum(1,n,1,a,b) << '\n';
        update(1,n,1,c,d);
        number[c] = d;
    }
}