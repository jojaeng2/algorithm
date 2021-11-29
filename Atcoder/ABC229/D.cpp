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
#define NUM 200010
#define INF 987654321
#define MOD 1000000007
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, double> piib;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
string s;
int k, psum[NUM], answer;

void init() {
	memset(psum, 0, sizeof(psum));
	cin >> s >> k;
	for(int i=0; i<s.size(); i++) {
		if(s[i] == '.') psum[i+1] = psum[i] + 1;
		else psum[i+1] = psum[i];
	}
	int l = 1, r = s.size();
	while(l<=r) {
		int mid = (l+r)/2;
		bool flag = true;
		for(int i=1; i<=s.size(); i++) {
			if(i+mid-1 > s.size()) break;
			if(psum[i+mid-1] - psum[i-1] <= k) {
				flag = false;
				break;
			}
		}
		if(!flag) {
			answer = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	cout << answer << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}