#include <bits/stdc++.h>
#define MINF 0x7f7f7f7f
#define X first
#define Y second
#define MOD 1000000007
#define NUM 500010
#define INF 1e17
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll cnt[NUM], answer = 0;
int n;
stack<pii> s;

void init() {
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    for(int i=0; i<n; i++) {
        int x, c;
        cin >> x;
        c = 1;
        while(!s.empty()) {
            auto curr = s.top();
            if(curr.Y <= x) {
                answer += (ll)s.top().X;
                if(curr.Y == x) c = curr.X + 1;
                s.pop();
            }
            else {
                answer++;
                break;
            }
        }
        s.push({c, x});
    }
    cout << answer << '\n';
}


int main() {    
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}


