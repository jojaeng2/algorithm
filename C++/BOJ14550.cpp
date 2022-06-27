#include <bits/stdc++.h>
#define MINF 0x7f7f7f7f7f7f7f
#define INF 1000000000
#define MOD 1000000007
#define NUM 200010
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N, S, T, DP[210][210], score[210];


void init() {
	while(true) {
		cin >> N;
		if(N == 0) break;
		for(int i=0; i<210; i++) for(int j=0; j<210; j++) DP[i][j] = -1000000;
		memset(score, 0, sizeof(score));
		cin >> S >> T;
		for(int i=1; i<=N; i++) cin >> score[i];
		DP[0][0] = 0;
		for(int i=1; i<=N+1; i++) {
			for(int j=1; j<=T; j++) {
				for(int k=1; k<=S; k++) {
					if(i-k < 0) continue;
					DP[j][i] = max(DP[j][i], DP[j-1][i-k] + score[i]);

				}
			}
		}
		int answer = -INF;
		for(int i=1; i<=T; i++) {
			answer = max(answer, DP[i][N+1]);
		}
		cout << answer << '\n';
	}

}


int main() {    
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}