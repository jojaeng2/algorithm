#include <iostream>
#include <vector>
#include <map>
#define NUM 500001
using namespace std;
typedef long long ll;
int n,A[NUM];
map<int,int> B;
ll tree[4*NUM],result;

void update(int start,int end,int node,int index){
    if(index < start || index > end) return;
    tree[node] += 1;
    if(start==end) return;
    int mid = (start+end)/2;
    update(start,mid,node*2,index);
    update(mid+1,end,node*2+1,index);
}

ll sum(int start,int end,int node,int left,int right){
    if(left > end || right < start) return 0;
    if(left<= start && end<=right) return tree[node];
    int mid = (start+end)/2;
    return sum(start,mid,node*2,left,right) + sum(mid+1,end,node*2+1,left,right);   
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> A[i];
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        B.insert(make_pair(a,i));
    }
    for(int i=1;i<=n;i++){
        int idx = B[A[i]];
        result += sum(1,n,1,idx+1,n);
        update(1,n,1,idx);
    }
    cout << result << '\n';
}