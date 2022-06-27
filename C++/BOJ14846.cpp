#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <map>
#define X first
#define Y second
#define INF 1e14
#define NUM 310
#define MOD 998244353
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
int psum[NUM][NUM][11], n, m, num[NUM][NUM];

void init() {
	memset(psum, 0, sizeof(psum));
	memset(num, 0, sizeof(num));
	cin >> n;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> num[i][j];
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			psum[i][j][num[i][j]]++;
			for(int k=1; k<=10; k++) {
				psum[i][j][k] += (psum[i-1][j][k] + psum[i][j-1][k] -psum[i-1][j-1][k]);
			}
		}
	}	

	cin >> m;
	for(int i=0; i<m; i++) {
		int x1, y1, x2, y2, cnt = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for(int j=1; j<=10; j++) {
			if(psum[x2][y2][j] - psum[x1-1][y2][j] - psum[x2][y1-1][j] +  psum[x1-1][y1-1][j] > 0) cnt++;
		}
		cout << cnt << '\n';
	}	
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}