#include <iostream>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
int n, DP[101][101], answer = 0;
int conn[101][101];

void dynamic() {
    for(int i=100; i>0; i--) for(int j=i; j<=100; j++) for(int k=i; k<j; k++) {
        DP[i][j] = max(DP[i][j], DP[i][k] + DP[k][j] + conn[i][j]);
        answer = max(answer, DP[i][j]);
    }   
    cout << answer << '\n';
    for(int i=1; i<=100; i++) {
        for(int j=1; j<=100; j++) {
            cout << DP[i][j] << " "; 
        }
        cout << '\n';
    }
}
void init() {
    memset(DP, 0, sizeof(DP));
    memset(conn, 0, sizeof(conn));
    cin >> n;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        if(a>b) conn[b][a] = 1;
        else conn[a][b] = 1;
    }
}

int main() {
    init();
    dynamic();
}