#include <iostream>
#include <cstring>
using namespace std;
int n,res=0;
int children[1000001],dp[1000001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(dp,dp+1000001,0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> children[i];

	for(int i=1;i<=n;i++){
		dp[children[i]] = max(dp[children[i-1]],dp[children[i]-1]+1);
		res = max(res,dp[children[i]]);
	}
	cout << n-res<< '\n';
}