#include <iostream>
#include <cstring>
#define INF 987654321
using namespace std;

int n, m, DP[101][101];

void print() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(DP[i][j] == INF) cout << "0 ";
			else cout << DP[i][j] << " ";
		}
		cout << '\n';
	}
}

void floyd() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			for(int p=1; p<=n; p++) {
				DP[j][p] = min(DP[j][p], DP[j][i] + DP[i][p]);
			}
		}
	}
}

void init() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0; i<101; i++) fill(DP[i], DP[i]+101, INF);
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		DP[a][b] = min(DP[a][b], c);
	}
	for(int i=1; i<=n; i++) DP[i][i] = 0;
}

int main() {
	init();
	floyd();
	print();
}