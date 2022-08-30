#include <bits/stdc++.h>
#define MINF 0x7f7f7f7f
#define INF 1000000000
#define MOD 10000
#define NUM 500010
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<float, pii> pfii;
typedef pair<ll, ll> pll;
int N, Q, num[NUM], curr = 0;
set<int> st;

void init() {
    memset(num, 0, sizeof(num));
    cin >> N >> Q;
    for(int i=0; i<N; i++) {
        cin >> num[i];
        if(num[i]) st.insert(i);
    }
    for(int i=0; i<Q; i++) {
        int x, y;
        cin >> x;
        if(x == 1) {
            cin >> y;
            y--;
            if(num[y]) {
                num[y] = 0;
                st.erase(y);
            }
            else {
                num[y] = 1;
                st.insert(y);
            }
        }
        if(x == 2) {
            cin >> y;
            curr = ((curr + y)%N);
        }
        if(x == 3) {
            if(st.size() == 0) cout << -1 << '\n';
            else {
                auto idx = st.lower_bound(curr);
                if(idx == st.end()) {
                    idx = st.lower_bound(-1);
                    cout << (N-curr) + (*idx) << '\n'; 
                }
                else cout << (*idx) - curr << '\n';
            } 
        }
    }
}

int main() {   
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
}