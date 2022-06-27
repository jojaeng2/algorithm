#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,sum=0;
vector<int> v;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for(int i=1;i<=n;i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	int left = 1, right = v[n-1]-v[0], answer = 0;
	int d = 0;
	while(left<=right){
		int cnt = 1, now = v[0];
		int mid = (left+right)/2;
		for(int i=1;i<n;i++){
			d = v[i]-now;
			if(d>=mid){
				now = v[i];
				cnt++;
			}
		}
		if(cnt>=m) {
			left = mid+1;
			answer = max(answer,mid);
		}
		else right = mid-1;
	}
	cout << answer << '\n';
}