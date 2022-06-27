#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
int dp[10001],n,m;
vector<pii> v[10001];

int main(){
	fill(dp,dp+10001,987654321);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		int a,b,c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b,c));
	}
	for(int i=0;i<=m;i++){
		if(i==0) dp[i] = 0;
		else dp[i] = min(dp[i],dp[i-1]+1);
		for(int j=0;j<v[i].size();j++){
			int next = v[i][j].X;
			int cost = v[i][j].Y;
			dp[next] = min(dp[i]+cost,dp[next]);
		}
	}
	cout << dp[m] << '\n';
}