#include <bits/stdc++.h>
#define MINF 0x7f7f7f7f
#define INF 2147483647
#define MOD 10000
#define NUM 200010
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<float, pii> pfii;
typedef pair<ll, ll> pll;
int N, M, h[NUM];
ll psum[NUM], answer = 0;
vector<int> v;

void init() {
    memset(h, 0, sizeof(h));
    memset(psum, 0, sizeof(psum));

    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        int x, y;
        cin >> x >> y;
        h[i] = y;
        v.push_back(y);
    }   
    sort(v.begin(), v.end());
    for(int i=0; i<M; i++) {
        int x, y;
        ll c;
        cin >> x >> y >> c;
        if(h[x] > h[y]) swap(x, y);
        int left = lower_bound(v.begin(), v.end(), h[x]) - v.begin();
        int right = lower_bound(v.begin(), v.end(), h[y]) - v.begin();
        psum[left] += c;
        psum[right+1] -= c;
    }
    for(int i=1; i<N; i++) psum[i] += psum[i-1];
    for(int i=0; i<=N; i++) {
        answer = max(answer, psum[i]);
    }
    cout << answer << '\n';
}

int main() {   
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
}