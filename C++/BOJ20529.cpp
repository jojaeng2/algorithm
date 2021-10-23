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
#define X first
#define Y second
#define NUM 100010
#define INF 1e15
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int t, n;
set<string> s;
vector<string> v;

void init() {
	cin >> t;
	while(t--) {
		cin >> n;
		s.clear();
		v.clear();
		for(int i=0; i<n; i++) {
			string str;
			cin >> str;
			v.push_back(str);
		}
		if(n > 32) {
			cout << 0 << '\n';
		}
		else {
			int answer = 1e9;
			for(int i=0; i<v.size(); i++) {
				for(int j=0; j<v.size(); j++) {
					for(int k=0; k<v.size(); k++) {
						int now = 0;
						if(i==j || i==k || j==k) continue;
						for(int p=0; p<4; p++) {
							if(v[i][p] != v[j][p]) now++;
							if(v[i][p] != v[k][p]) now++;
							if(v[j][p] != v[k][p]) now++;
						}
						answer = min(answer, now);
					}
				}
			}
			cout << answer << '\n';
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}