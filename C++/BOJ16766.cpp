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
#define NUM 100010
#define INF 1000000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int N, M, C, L = 0, R = INF, answer;
vector<int> v;

void init() {
	cin >> N >> M >> C;
	for(int i=0; i<N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	while(L<=R) {
		int mid = (L+R)/2, psum = 1, cnt = 0;
		int idx = 0;
		for(int i=0; i<N; i++) {
			int next = v[i];
			if(cnt < C && next <= v[idx]+mid) cnt++;
			else {
				cnt = 1;
				idx = i;
				psum++;
			}
		}
		if(psum<=M) {
			answer = mid;
			R = mid-1;
		}
		else L = mid+1;
	}
	cout << answer << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}