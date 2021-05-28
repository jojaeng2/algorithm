#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int DP[100010][5][5], answer=1e9;
vector<int> v;

void print() {
    for(int i=0; i<5; i++) for(int j=0; j<5; j++) answer = min(answer, DP[v.size()][i][j]);
    cout << answer << '\n';
}

int find(int next, int now) {
    int cnt = 3, opp;
    if(next == 1) opp = 3;
    else if(next == 2) opp = 4;
    else if(next == 3) opp = 1;
    else opp = 2;

    if(now == 0) cnt = 2;
    else if(next == now) cnt = 1;
    else if(now == opp) cnt = 4;

    return cnt;
}

void dynamic() {
    for(int k=0; k<v.size(); k++) {
        if(k==0) DP[1][v[0]][0] = 2, DP[1][0][v[0]] = 2;
        int next = v[k];
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                if(DP[k][i][j] == 0) continue;
                int a = find(next, i), b = find(next, j);
                DP[k+1][next][j] = min(DP[k+1][next][j], DP[k][i][j] + a);
                DP[k+1][i][next] = min(DP[k+1][i][next], DP[k][i][j] + b);
            }
        }
    }
}

void init() {
    memset(DP, 1e6, sizeof(DP));
    while(true) {
        int next;
        cin >> next;
        if(next == 0) break;
        v.push_back(next);
    }
}

int main() {
    init();
    dynamic();
    print();
}