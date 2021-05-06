#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, row[1501][1501], column[1501][1501], dp[1501][1501];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(row,0,sizeof(row));
	memset(column,0,sizeof(column));
	memset(dp,0,sizeof(dp));

	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char ch;
			int k;
			cin >> ch >> k;
			row[i][j] = row[i][j-1];
			column[i][j] = column[i-1][j];
			if(ch == 'B'){
				int num = k;
				column[i][j] += num;
			}
			else {
				int num = k;
				row[i][j] += num;
			}
		}
	}
	
	for(int i=2;i<=n;i++) {
		for(int j=2;j<=m;j++) {
			dp[i][j] = max({dp[i][j], dp[i-1][j-1] + column[i-1][j] + row[i][j-1], dp[i-1][j] + row[i][j-1], dp[i][j-1] + column[i-1][j]});
		}
	}

	cout << dp[n][m] << '\n';
}