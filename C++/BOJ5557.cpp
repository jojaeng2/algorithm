#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int n, number[101];
ll ans = 0, DP[101][21];


int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(DP,0, sizeof(DP));

	cin >> n;
	for(int i=1;i<=n;i++) {
		int a;
		cin >> a;
		if(i == 1) DP[1][a] = 1;
		for(int j=0;j<=20;j++) {
			if(a + j <= 20) DP[i][j+a] += DP[i-1][j];
			if(j-a >= 0) DP[i][j-a] += DP[i-1][j];
		}
		if(i == n) {
			cout << DP[i-1][a] << '\n';
		}
	}

}