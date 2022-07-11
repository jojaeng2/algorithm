#include <bits/stdc++.h>
#define MINF 0x7f7f7f7f7f7f7f
#define INF 1000000000
#define MOD 10000
#define NUM 2000100
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
int N, psum[NUM], answer = 0;
map<int, int> mp, bef;
vector<pii> v;

bool compare(pii a, pii b) {
    return a.Y < b.Y;
}

void init() {
    memset(psum, 0, sizeof(psum));
    cin >> N;    
    for(int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), compare);
    int idx = 1;
    for(auto curr : v) {
        mp[idx] = curr.Y;
        if(curr.X == 0) psum[idx]++;
        else psum[idx]--;
        idx++;
    }
    bef[0] = 1;
    for(int i=1; i<idx; i++) psum[i] += psum[i-1];
    for(int i=1; i<idx; i++) {
        if(bef[psum[i]] != 0) answer = max(answer, mp[i] - mp[bef[psum[i]]]);
        else bef[psum[i]] = i+1;
    }
    cout << answer << '\n';
}


int main() {    
    ios_base :: sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   init();
}