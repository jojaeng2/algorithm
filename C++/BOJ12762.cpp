#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
int n, num[1010], answer = 1;
vector<int> lo, hi;
void init() {
	cin >> n;
	for(int i=1; i<=n; i++) cin >> num[i];
	for(int i=2; i<=n; i++) {
		hi.clear(), lo.clear();
		hi.push_back(num[i]);
		lo.push_back(num[i]);
		for(int j=i+1; j<=n; j++) {
			if(num[j] > hi.back()) hi.push_back(num[j]);
			else {
				int idx = lower_bound(hi.begin(), hi.end(), num[j]) - hi.begin();
				hi[idx] = num[j];
			}
		}
		for(int j=i-1; j>0; j--) {
			if(num[j] > lo.back()) lo.push_back(num[j]);
			else {
				int idx = lower_bound(lo.begin(), lo.end(), num[j]) - lo.begin();
				lo[idx] = num[j];
			}
		}
		int now = lo.size() + hi.size()-1;
		answer = max(answer, now);
	}
	cout << answer << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
