#include <iostream>
#include <cstring>
using namespace std;
int n,l,graph[101][101],log[101][101],cnt=0;
bool visit[101][101];

void check(int start){
	for(int i=2;i<=n;i++){
		if(abs(graph[start][i]-graph[start][i-1])==0) continue;
		if(abs(graph[start][i]-graph[start][i-1])!=1) return;
		if(graph[start][i]<graph[start][i-1]){
			if(visit[start][i] || i+l-1>n) return;
			visit[start][i] = true;

			for(int j=i+1;j<i+l;j++){
				if(graph[start][j]!=graph[start][j-1] || visit[start][j]){
					for(int p=i;p<j;p++) visit[start][p] = false;
					return;
				} 
				visit[start][j] = true;
			}
		}	
		else{
			if(visit[start][i-1] || i-l<1) return;
			visit[start][i-1] = true;
			for(int j=i-1;j>i-l;j--){
				if(graph[start][j]!=graph[start][j-1] || visit[start][j-1]) {
					for(int p=i-1;p>j;p--) visit[start][p] = false;
					return;
				}
				visit[start][j] = true;
			}
		}
	}
	cnt++;
}

int main(){
	cin >> n >> l;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
		cin >> graph[i][j];
		log[i][j] = graph[i][j];
	}
	for(int i=1;i<=n;i++) check(i);
	memset(visit,false,sizeof(visit));
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) graph[i][j] = log[j][i];
	for(int i=1;i<=n;i++) check(i);
	cout << cnt << '\n';
}