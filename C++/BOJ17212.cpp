#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cmath>
#include <deque>
#include <list>
#define X first
#define Y second
#define NUM 100100
#define INF 1000000000
#define MOD 1000000007
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int coins[4] = {7, 5, 2, 1}, N, DP[NUM];

void init() {
	cin >> N;
	for(int i=0; i<=N; i++) DP[i] = INF;
	DP[0] = 0;
	for(int i=0; i<4; i++) {
		int coin = coins[i];
		for(int j=coin; j<=N; j++) {
			DP[j] = min(DP[j], DP[j-coin]+1);
		}
	}
	cout << DP[N] << '\n';
}	

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}