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
#include <cmath>
#define X first
#define Y second
#define NUM 100100
#define INF 1000000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int n, m, dfsn[NUM], cnt = 1, bccnt[NUM];
bool flag = false;
stack<pii> s;
vector<int> adj[NUM];
vector<vector<pii>> BCC;
set<int> st;

int dfs(int curr, int prev=-1) {
    dfsn[curr] = cnt++;
    int res = dfsn[curr];
    for(auto next : adj[curr]) {
        if(next == prev) continue;
        if(dfsn[curr] > dfsn[next]) s.push({curr, next});
        if(dfsn[next] > 0) res = min(res, dfsn[next]);
        else {
            int temp = dfs(next, curr);
            res = min(res, temp);
            if(temp >= dfsn[curr]) {
                vector<pii>currBCC;
                while(!s.empty()) {
                    if(s.top() == pii(curr, next)) break;
                    currBCC.push_back(s.top());
                    s.pop();
                }
                currBCC.push_back(s.top());
                s.pop();
                BCC.push_back(currBCC);
            }
        }
    }
    return res;
}

void init() {
    cin >> n >> m;
    memset(dfsn, 0, sizeof(dfsn));
    memset(bccnt, 0, sizeof(bccnt));
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1; i<=n; i++) {
        if(!dfsn[i]) dfs(i);
    }
    for(auto bcc:BCC) {
		cout << -1 << '\n';
        st.clear();
        for(auto x : bcc) {
			cout << x.X << " " << x.Y << '\n';
            st.insert(x.first);
            st.insert(x.second);
        }
		cout << st.size() << " " << bcc.size() << '\n';
        if(st.size() <= 2) continue;
        if(st.size() != bcc.size()) flag = true;
        for(auto x : st) {
            bccnt[x]++;
            if(bccnt[x]>=2) flag = true;
        }
    }
    if(!flag) cout << "Cactus" << endl;
    else cout << "Not cactus" << endl;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}