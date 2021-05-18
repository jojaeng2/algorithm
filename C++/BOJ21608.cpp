#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct students{
	int num, a, b, c, d;
};

int n;
int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, -1, 1};
long long answer = 0;
int graph[21][21];
vector<students> v;

void print() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int cnt = 0;
			for(int p=0; p<v.size(); p++) {
				int now = v[p].num;
				if(graph[i][j] == now) {
					for(int k=0; k<4; k++) {
						int nx = i+dx[k], ny = j + dy[k];
						if(0>nx || nx>=n || 0>ny || ny>=n) continue;
						if(graph[nx][ny] == v[p].a || graph[nx][ny] == v[p].b || graph[nx][ny] == v[p].c || graph[nx][ny] == v[p].d) cnt++;
					}
					break;
				}
			}
			if(cnt == 0) answer += 0;
			else if(cnt == 1) answer++;
			else if(cnt == 2) answer += 10;
			else if(cnt == 3) answer += 100;
			else answer += 1000;
		}
	}
	cout << answer << '\n';
}

void calc(students student) {
	int x = 0, y = 0, blank = -1, friendly = -1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int new_blank = 0, new_friendly = 0;
			if(graph[i][j] != 0) continue;
			for(int p=0; p<4; p++) {
				int nx = i + dx[p], ny = j + dy[p];
				if(0<=nx && nx<n && 0<=ny && ny<n) {
					if(graph[nx][ny] == student.a || graph[nx][ny] == student.b || graph[nx][ny] == student.c || graph[nx][ny] == student.d) new_friendly++;
					else if(graph[nx][ny] == 0) new_blank++;
				}
			}
			if(friendly < new_friendly) {
				x = i, y = j;
				blank = new_blank, friendly = new_friendly;
			}
			else if(friendly == new_friendly && blank < new_blank) {
				x = i, y = j;
				blank = new_blank, friendly = new_friendly;
			}
		}
	}
	graph[x][y] = student.num;
}

void position() {
	for(int i=0; i<v.size(); i++) {
		students student = v[i];
		calc(student);
	}
}

void init() {
	memset(graph, 0, sizeof(graph));
	cin >> n;
	for(int i=0; i<n*n; i++) {
		students student;
		cin >> student.num >> student.a >> student.b >> student.c >> student.d;
		v.push_back(student);
	}
}

int main() {
	init();
	position();
	print();
}