#include <iostream>
#include <algorithm>
#include <vector>
#define X first
#define Y second
#define NUM 500001
using namespace std;
typedef pair<int,int> pii;
int n,tree[4*NUM],ans[NUM];
vector<pii> v;


int sum(int start,int end,int node,int right){
	if(right<start || tree[node]==0) return 0;
	if(1<=start && end<=right) return tree[node];
	int mid = (start+end)/2;
	return sum(start,mid,node*2,right) + sum(mid+1,end,node*2+1,right); 
}

void update(int start,int end,int node,int index){
	if(index<start || end<index) return;
	tree[node]++;
	if(start==end) return;
	int mid = (start+end)/2;
	update(start,mid,node*2,index);
	update(mid+1,end,node*2+1,index);
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i=1;i<=n;i++){
		int a;
		cin >> a;
		v.push_back(make_pair(a,i));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		int idx = v[i].Y;
		ans[idx] = idx - sum(1,n,1,idx-1);
		update(1,n,1,idx);
	}
	for(int i=1;i<=n;i++) cout << ans[i] << '\n';
}