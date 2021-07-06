#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define NUM 500010
using namespace std;
typedef pair<int, int> pii;
int n, par[NUM], trace[NUM];
bool visit[NUM] = {false};
vector<pii> v;
vector<int> LIS, answer;

void print() {
    for(int i=0; i<v.size(); i++) {
        int x = v[i].first, y = v[i].second;
        if(!visit[x]) answer.push_back(x);
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for(int i=0; i<answer.size(); i++) {
        cout << answer[i] << '\n';
    }
}

void dfs(int s) {
    int next = trace[s];
    if(next == -1) return;
    visit[par[next]] = true;
    dfs(next);
}

void solve() {
    LIS.push_back(-1);
    for(int i=0; i<v.size(); i++) {
        int next = v[i].second;
        if(LIS.back() < next) {
            trace[next] = LIS.back();
            LIS.push_back(next);
        }
        else {
            int idx = lower_bound(LIS.begin(), LIS.end(), next) - LIS.begin();
            LIS[idx] = next;
            if(idx == 0) trace[v[i].second] = -1;
            else trace[v[i].second] = LIS[idx-1];
        }
    }
    visit[par[LIS.back()]] = true;
    dfs(LIS.back());
}

void reset() {
    memset(par, 0, sizeof(par));
    memset(trace, -2, sizeof(trace));    
}

bool compare(pii a, pii b) {
    return a.first < b.first;
}

void init() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    reset();
    cin >> n;
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        par[y] = x;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), compare);
}

int main() {
    init();
    solve();
    print();
}