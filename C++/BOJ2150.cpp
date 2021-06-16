#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
int v, e, dfsn[10001], sn = 1, cnt = 1;
vector<int> graph[10001];
vector<vector<int> > ans;
bool visit[10001];
stack<int> stak;

bool compare(vector<int> a, vector<int> b) {
    return a.front() < b.front();
}

void print() {
    sort(ans.begin(), ans.end(), compare);
    cout << ans.size() << '\n';
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}


int dfs(int s) {
    dfsn[s] = cnt++;
    int res = dfsn[s];
    stak.push(s);

    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i];
        if(dfsn[next] == 0) res = min(res, dfs(next));
        else if(!visit[next]) res = min(res, dfsn[next]);
    }
    if(res == dfsn[s]) {
        vector<int> v;
        while(true) {
            int tp = stak.top();
            stak.pop();
            v.push_back(tp);
            visit[tp] = true;
            if(tp == s) break;
        }
        sort(v.begin(), v.end());
        v.push_back(-1);
        ans.push_back(v);
    }
    return res;
}

void init() {
    memset(dfsn, 0, sizeof(dfsn));
    memset(visit, false, sizeof(visit));
    cin >> v >> e;
    for(int i=0; i<e; i++) {
        int s, e; 
        cin >> s >> e;
        graph[s].push_back(e);
    }
    for(int i=1; i<=v; i++) {
        if(dfsn[i] == 0) dfs(i);
    }
}

int main() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    init();
    print();
}