#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <iomanip>
#include <string>
#include <sstream>
#define X first
#define Y second
#define NUM 1010
#define INF 1e15
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
int num[NUM][NUM], bfsn[NUM][NUM], psum[NUM*NUM], n, m, answer = 0, cnt, bcnt = 1, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
bool visit[NUM][NUM];
set<int> st;
queue<pii> q;

void bfs(int s) {
	while(!q.empty()) {
		int x = q.front().X, y = q.front().Y;
		q.pop();
		for(int i=0; i<4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 1 || ny < 1 || nx > n || ny > m || !num[nx][ny] || visit[nx][ny]) continue;
			visit[nx][ny] = true;
			bfsn[nx][ny] = s;
			cnt++;
			q.push({nx, ny});
		}
	}
}

void init() {
	memset(num, 0, sizeof(num));
	memset(bfsn, 0, sizeof(bfsn));
	memset(psum, 0, sizeof(psum));
	memset(visit, false, sizeof(visit));
	cin >> n >> m;
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin >> num[i][j];
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) {
		if(num[i][j] && !visit[i][j]) {
			visit[i][j] = true;
			q.push({i, j});
			cnt = 1;
			bfsn[i][j] = bcnt;
			bfs(bcnt);
			psum[bcnt++] = cnt;
			answer = max(answer, cnt);
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(!num[i][j]) {
				int bpsum = 1;
				st.clear();
				for(int k=0; k<4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if(nx < 1 || ny < 1 || nx > n || ny > m || st.find(bfsn[nx][ny]) != st.end()) continue;
					st.insert(bfsn[nx][ny]);
					bpsum += psum[bfsn[nx][ny]]; 
				}
				answer = max(answer, bpsum);
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