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
#define NUM 100
#define INF 1000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int y;
string s, x;

void init() {
	cin >> s;
	for(int i=0; i<s.size(); i++) {
		if(s[i] == '.') {
			y = s[i+1] - '0';
			break;
		}
		x += s[i];
	}
	if(y >= 0 && y<=2) cout << x << '-' << '\n';
	else if(y>=3 && y<=6) cout << x << '\n';
	else cout << x << '+' << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}