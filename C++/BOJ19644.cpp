#include <iostream>
#include <cstring>
#include <algorithm>
#define NUM 3000010
using namespace std;
int arr[2*NUM], n, m, k, t, cnt[NUM], psum = 0;

void solve() {
    bool flag = false;
    int psum = 1, left = 1, right = m;
    while(left<=n) {
        cnt[right+1] = psum;
        if((psum - cnt[left]) * k >= arr[left]) psum++, left++, right++;
        else {
            if(t > 0) t--, left++, right++;
            else {
                flag = true;
                break;
            }
        }
    }
    if(flag) cout << "NO" << '\n';
    else cout << "YES" << '\n';
}

void init() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    memset(arr, 0, sizeof(arr));
    memset(cnt, 0, sizeof(cnt));
    cin >> n >> m >> k >> t;
    for(int i=1; i<=n; i++) cin >> arr[i];
}

int main() {
    init();
    solve();
}