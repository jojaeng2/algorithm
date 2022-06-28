#include <bits/stdc++.h>
#define MINF 0x7f7f7f7f7f7f7f
#define INF 1000000000
#define MOD 1000000007
#define NUM 100010
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
int N, M, T, K, A, B;
char graph[510][510];

void start() {
	char ngraph[510][510];
	int psum[510][510];
	memset(psum, 0, sizeof(psum));
	for(int i=1; i<=500; i++) for(int j=1; j<=500; j++) ngraph[i][j] = '.';
	for(int i=1; i<=500; i++) for(int j=1; j<=500; j++) {
		psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
		if(graph[i][j] == '*') psum[i][j]++;
	}
	for(int i=110; i<N+110; i++) for(int j=110; j<M+110; j++) {
		int cnt = (psum[i+K][j+K] - psum[i-K-1][j+K] - psum[i+K][j-K-1] + psum[i-K-1][j-K-1]);
		if(graph[i][j] == '*') {
			cnt--;
			if(A <= cnt && cnt <= B) ngraph[i][j] = '*';
			if(A > cnt) ngraph[i][j] = '.';
			if(cnt > B) ngraph[i][j] = '.';
			
		}
		else {
			if(A < cnt && cnt <= B) ngraph[i][j] = '*';
		}
	} 
	for(int i=1; i<=500; i++) for(int j=1; j<=500; j++) graph[i][j] = ngraph[i][j];
}

void init() {
	cin >> N >> M >> T >> K >> A >> B;
	for(int i=1; i<=500; i++) for(int j=1; j<=500; j++) graph[i][j] = '.';
	for(int i=110; i<N+110; i++) {
		string str;
		cin >> str;
		for(int j=0; j<M; j++) {
			graph[i][j+110] = str[j];
		}
	}

	while(T--) {
		start();
	}
	for(int i=110; i<N+110; i++) {
		for(int j=110; j<M+110; j++) {
			cout << graph[i][j];
		}
		cout << '\n';
	}
}	


int main() {    
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}