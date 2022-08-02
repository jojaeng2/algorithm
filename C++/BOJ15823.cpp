#include <bits/stdc++.h>
#define MINF 0x7f7f7f7f
#define INF 300000000000
#define MOD 10000
#define NUM 100010
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
int N, M, answer;
vector<int> v;
vector<set<int>> res;

void init() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int left = 1, right = N/M;
    
    while(left <= right) {
        int mid = (left + right)/2;
        int l = 0, r = 0;
        res.clear();
        set<int> s;
        while(l <= r && r <v.size()) {
            bool flag;
            int num = v[r];
            if(s.find(num) != s.end()) {
                s.erase(v[l++]);
                flag = false;
            }
            else {
                s.insert(num);
                flag = true;
                r++;
            }
            if(s.size() == mid) {
                res.push_back(s);
                s.clear();
                if(!flag) r++, l = r;
                else l = r;
            }
        }
        if(res.size() >= M) {
            answer = mid;
            left = mid+1;
        }
        else right = mid-1;
    }   
    cout << answer << '\n';
}

int main() {   
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
}