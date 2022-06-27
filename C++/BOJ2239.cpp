#include <iostream>
#include <vector>
#include <string>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
int graph[10][10];
vector<pii> blank;
bool three_visit[3][3][10],flag=false;

void dfs(int cnt){
	if(cnt==blank.size()){
		flag=true;
		return;
	}
	int x = blank[cnt].X;
	int y = blank[cnt].Y;
	bool now_visit[10] = {false};

	
	for(int i=1;i<=9;i++){
		if(graph[x][i]!=0) now_visit[graph[x][i]] = true;
	}
	for(int i=1;i<=9;i++){
		if(graph[i][y]!=0) now_visit[graph[i][y]] = true;
	}
	for(int i=1;i<=9;i++){
		if(three_visit[(x-1)/3][(y-1)/3][i]) now_visit[i] = true;
	}
	for(int i=1;i<=9;i++){
		if(!now_visit[i]){
			graph[x][y] = i;
			three_visit[(x-1)/3][(y-1)/3][i] = true;
			dfs(cnt+1);
			if(flag){
				return;
			}
			graph[x][y] = 0;
			three_visit[(x-1)/3][(y-1)/3][i] = false;
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=1;i<=9;i++){
		string s;
		cin >> s;
		for(int j=0;j<9;j++){
			graph[i][j+1] = s[j]-'0';
			if(graph[i][j+1]==0) blank.push_back(make_pair(i,j+1));
			else{
				three_visit[(i-1)/3][(j)/3][graph[i][j+1]] = true;
			}
		}
	}
	dfs(0);
	cout << endl;
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			cout << graph[i][j] << "";
		}
		cout << endl;
	}
}