#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, m;
vector<ll> A, B;
ll now;

void print() {
    for(int i=0; i<B.size(); i++) {
        ll dat, next = B[i] + A[0], aa = now;
        while(aa != 0) {
            dat = next % aa;
            next = aa;
            aa = dat;
        }
        cout << next << " ";
    }
    cout << '\n';
}

void gcd() {
    if(n == 1) {
        for(int i=0; i<m; i++) {
            cout << A[0] + B[i] << ' ';
        }
        cout << '\n';
    }
    else {
        now = A[1] - A[0];
        for(int i=2; i<A.size(); i++) {
            ll dat, next = A[i] - A[0];
            while(now != 0) {
                dat = next % now;
                next = now;
                now = dat;
            }
            now = next;
        }
        print();
    }
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        ll num;
        cin >> num;
        A.push_back(num);
    }
    for(int i=0; i<m; i++) {
        ll num;
        cin >> num;
        B.push_back(num);
    }
    sort(A.begin(), A.end());
}


int main() {
    init();
    gcd();
}