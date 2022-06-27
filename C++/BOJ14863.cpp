#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

ll DP[100001], cpy[100001];
int n, k;

void print() {
	ll cnt = -1;
	for(int i=0; i<=k; i++) cnt = max(cnt, DP[i]);
	cout << cnt << '\n';
}

void init() {
	memset(DP, -1, sizeof(DP));
	DP[0] = 0;
	cin >> n >> k;
	for(int i=1; i<=n; i++) {
		memset(cpy, -1, sizeof(cpy));
		int walk_time, walk_cost, ride_time, ride_cost;
		cin >> walk_time >> walk_cost >> ride_time >> ride_cost;
		for(int j=0; j<=k;j++) {
			if(DP[j] != -1) {
				if(j + walk_time <= k) {
					cpy[j+walk_time] = max(cpy[j+walk_time], DP[j] + walk_cost);
				}
				if(j + ride_time <= k) {
					cpy[j+ride_time] = max(cpy[j+ride_time], DP[j] + ride_cost);
				}
			}
		}
		for(int j=0; j<=k; j++) DP[j] = cpy[j];
	}
}

int main() {
	init();
	print();
}