#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
struct acorn {
    int s, e, dist;
};
int n, k;
ll d;
vector<acorn> v;

void solve() {
    int l = 1, r = 1000000;
    while(l < r) {
        int mid = (l+r)/2;
        ll cnt = 0;
        for(int i=0; i<k; i++) {
            if(mid < v[i].s) continue;
            cnt += (min(v[i].e, mid) - v[i].s) / v[i].dist;
            cnt++;
        }
        if(cnt >= d) r = mid;
        else l = mid+1;
    }
    cout << r << '\n';
}

void init() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> k >> d;
    for(int i=0; i<k; i++) {
        acorn ad;
        cin >> ad.s >> ad.e >> ad.dist;
        v.push_back(ad);
    }
}

int main() {
    init();
    solve();
}