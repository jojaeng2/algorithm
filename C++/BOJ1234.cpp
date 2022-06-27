#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
int n, r, g, b;
ll dp[11][110][110][110], answer=0, num[110];
ll dfs(int s, int x, int y, int z) {
	if(dp[s][x][y][z] != -1) return dp[s][x][y][z];
	dp[s][x][y][z] = 0;
	if(s == n) return dp[s][x][y][z] = 1;
	if(r-(x+s+1) >= 0) dp[s][x][y][z] += dfs(s+1, x+s+1, y, z);
	if(g-(y+s+1) >= 0) dp[s][x][y][z] += dfs(s+1, x, y+s+1, z);
	if(b-(z+s+1) >= 0) dp[s][x][y][z] += dfs(s+1, x, y, z+s+1); 
	if((s+1)%2 == 0) {
		int next = (s+1)/2;
		if(r-(x+next) >= 0 && g-(y+next) >= 0) dp[s][x][y][z] += (dfs(s+1, x+next, y+next, z) * (num[s+1] / pow(num[next], 2)));
		if(r-(x+next) >= 0 && b-(z+next) >= 0) dp[s][x][y][z] += (dfs(s+1, x+next, y, z+next) * (num[s+1] / pow(num[next], 2)));
		if(g-(y+next) >= 0 && b-(z+next) >= 0) dp[s][x][y][z] += (dfs(s+1, x, y+next, z+next) * (num[s+1] / pow(num[next], 2)));
	}
	if((s+1)%3 == 0) {
		int next = (s+1)/3;
		if(r-(x+next) >= 0 && g-(y+next) >= 0 && b-(z+next) >= 0) dp[s][x][y][z] += (dfs(s+1, x+next, y+next, z+next) * num[s+1]/pow(num[next],3));
	}
	return dp[s][x][y][z];
}

void init() {
	memset(dp, -1, sizeof(dp));
	memset(num, 0, sizeof(num));
	num[0] = 1;
	for(int i=1; i<=100; i++) num[i] = num[i-1]*i; 
	cin >> n >> r >> g >> b;
	if(r > 0) dfs(1, 1, 0, 0);
	if(g > 0) dfs(1, 0, 1, 0);
	if(b > 0) dfs(1, 0, 0, 1);
	if(dp[1][1][0][0] != -1) answer += dp[1][1][0][0];
	if(dp[1][0][1][0] != -1) answer += dp[1][0][1][0];
	if(dp[1][0][0][1] != -1) answer += dp[1][0][0][1];
	cout << answer << '\n';
}

int main() {
	init();
}