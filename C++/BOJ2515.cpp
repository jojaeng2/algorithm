#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
int n, s, DP[300001];
vector<pii> v;

bool compare(pii a, pii b) {
    return a.X < b.X;
}

void dynamic() {
    for(int i=1; i<=n; i++) {
        int now = v[i].X, cost = v[i].Y;
        if(now - s <= 0) DP[i] = max(DP[i-1], cost);
        else {
            int idx = upper_bound(v.begin(), v.end(), pii(now-s, 0), compare) - v.begin() - 1;
            DP[i] = max(DP[i-1], DP[idx] + cost);
        }
    }
    cout << DP[n] << '\n';
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(DP, 0, sizeof(DP));
    cin >> n >> s;
    v.push_back(make_pair(0, 0));
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end());
}

int main() {
    init();
    dynamic();
}