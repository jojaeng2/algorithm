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
#define NUM 10000
#define INF 1000000000010
#define MOD 1000000007
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
int n, b, w, answer = 0;
string s;

void init() {
	cin >> n >> b >> w >> s;
	int l = 0, r = 0, bb = 0, ww = 0;
	while(l <= r && r < n) {
		if(s[r++] == 'B') bb++;
		else ww++;
		if(bb <= b && ww >= w) answer = max(answer, r-l);
		if(bb > b) {
			if(s[l++] == 'W') ww--;
			else bb--;
		}
	}
	cout << answer << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}