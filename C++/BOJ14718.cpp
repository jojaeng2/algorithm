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
#define INF 1e9
#define NUM 100010
#define MOD 1000000007
using namespace std;
struct st {
	int x, y, z;
};
typedef pair<int, int> pii;
typedef long long ll;
int n, m, answer = INF;
vector<int> a, b, c;
st e[110];

void init() {
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> e[i].x >> e[i].y >> e[i].z;
		a.push_back(e[i].x);
		b.push_back(e[i].y);
		c.push_back(e[i].z);
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			for(int k=0; k<n; k++) {
				int x = a[i], y = b[j], z = c[k], cnt = 0;
				for(int p=0; p<n; p++) {
					if(x>=e[p].x && y>=e[p].y && z>=e[p].z) cnt++;
				}
				if(cnt>=m) answer = min(answer, x+y+z);
			}
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
