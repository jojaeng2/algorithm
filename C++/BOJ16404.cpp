#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
int t, n;
ll arr[200001];
void init() {
    cin >> t;
    while(t--) {
        cin >> n;
        ll answer = (n)*(n-1)/2;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        cout << answer << '\n';
    }
}

int main() {
    init();
}