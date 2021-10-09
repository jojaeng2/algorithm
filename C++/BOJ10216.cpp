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
#include <cmath>
using namespace std;
struct st {
	int x, y, z;
};
int t, n, par[5010], answer;
vector<st> v;

int find(int s) {
	if(s == par[s]) return s;
	return par[s] = find(par[s]);
}

void init() {
	cin >> t;
	while(t--){
		v.clear();
		answer = 0;
		cin >> n;
		for(int i=0; i<=n; i++) par[i] = i;
		for(int i=0; i<n; i++) {
			st s;
			cin >> s.x >> s.y >> s.z;
			v.push_back(s);	
		}
		for(int i=0; i<v.size(); i++) {
			for(int j=0; j<v.size(); j++) {
				if(i == j) continue;
				int a = find(i), b = find(j);
				if(a == b) continue;
			    int x1=v[i].x, y1=v[i].y, z1=v[i].z, x2=v[j].x, y2=v[j].y, z2=v[j].z;
			    if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<=(z1+z2)*(z1+z2)) {
			    	if(a<b) par[b] = a;
					else par[a] = b;
			    }
			}
		}
		
		for(int i=1; i<=n; i++) if(par[i] == i) answer++;
		cout << answer << '\n';
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}