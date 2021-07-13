#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#define NUM 100000001
using namespace std;
typedef long long ll;
int n, k;
ll answer = 0, cnt = 0;
map<int, ll> m;
queue<ll> q;

void bfs() {
    while(!q.empty()) {
        if(cnt == k) break;
        int x = q.front();
        q.pop();
        if(m.find(x+1) == m.end()) {
            q.push(x+1);
            m.insert(make_pair(x+1, m[x]+1));
            answer += m[x] + 1;
            cnt++;
        }
        if(cnt == k) break;
        if(m.find(x-1) == m.end()) {
            q.push(x-1);
            m.insert(make_pair(x-1, m[x] + 1));
            answer += m[x] + 1;
            cnt++;
        }
    }
}

void init() {
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        q.push(x + NUM);
        m.insert(make_pair(x+NUM, 0));
    }
}

int main() {
    init();
    bfs();
    cout << answer << '\n';
}
