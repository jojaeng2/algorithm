#include <bits/stdc++.h>
#define MINF 0x7f7f7f7f7f7f7f
#define INF 1000000000
#define MOD 10000
#define NUM 100010
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
struct st {
    int psum, x1, y1, x2, y2;
};
int N, M, graph[40][40], cnt[40][40], psum[40][40];
bool visited[40][40];
vector<st> v;

void init() {
    memset(visited, false, sizeof(visited));
    cin >> N >> M;
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) cin >> graph[i][j];
    bool flag = false;
    while(M--) {
        int maxi = -INF, x1, y1, x2, y2;
        memset(cnt, 0, sizeof(cnt));
        memset(psum, 0, sizeof(psum));
        for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) {
            if(visited[i][j]) {
                cnt[i][j]++;
                psum[i][j] = 0;
            }
            else {
                psum[i][j] = graph[i][j];
            }
        }
        for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) {
            cnt[i][j] = cnt[i][j] + cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
            psum[i][j] = psum[i][j] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
        }
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                for(int p=i+2; p<=N; p++) {
                    for(int q=j+2; q<=N; q++) {
                        int onion = cnt[p][q] - cnt[i-1][q] - cnt[p][j-1] + cnt[i-1][j-1] - (cnt[p-1][q-1] - cnt[i][q-1] - cnt[p-1][j] + cnt[i][j]);
                        int taste = psum[p][q] - psum[i-1][q] - psum[p][j-1] + psum[i-1][j-1] - (psum[p-1][q-1] - psum[i][q-1] - psum[p-1][j] + psum[i][j]);
                        if(onion) continue;
                        if(taste > maxi) {
                            maxi = taste;
                            x1 = i, y1 = j, x2 = p, y2 = q;
                        }
                    }
                }
            }
        }
        if(maxi == -INF) {
            flag = true;
            break;
        }
        else {
            st s;
            s.psum = maxi, s.x1 = x1, s.y1 = y1, s.x2 = x2, s.y2 = y2;
            v.push_back(s);
            for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) {
                if(x1 <= i && i <= x2 && (j == y1 || j == y2)) visited[i][j] = true;
                if(y1 <= j && j <= y2 && (i == x1 || i == x2)) visited[i][j] = true;
            }
        }
    }

    if(flag) {
        cout << 0 << '\n';
    }
    else {
        for(auto vv : v) {
            cout << vv.psum << " " << vv.x1 << " " << vv.y1 << " " << vv.x2 << " " << vv.y2 << '\n';
        }
    }
}   


int main() {    
    ios_base :: sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   init();
}