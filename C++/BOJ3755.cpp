#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
bool visit[1000010];
priority_queue<pii> lo, hi;

void init() {
	memset(visit, false, sizeof(visit));
	while(true) {
		bool flag = false;
		int x, y, z;
		cin >> x;
		if(x == 0) break;
		if(x == 1) {
			cin >> y >> z;
			lo.push({-z, y});
			hi.push({z, y});
			visit[y] = false;
		}
		else if(x == 2) {
			while(!hi.empty()) {
				int client = hi.top().Y;
				hi.pop();
				if(!visit[client]) {
					cout << client << '\n';
					visit[client] = true;
					flag = true;
					break;
				}
			}
			if(!flag) cout << 0 << '\n';
		}
		else {
			while(!lo.empty()) {
				int client = lo.top().Y;
				lo.pop();
				if(!visit[client]) {
					cout << client << '\n';
					visit[client] = true;
					flag = true;
					break;
				}
			}
			if(!flag) cout << 0 << '\n';
		}
	}

}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
