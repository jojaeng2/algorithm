#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct sharks {
	int x, y, speed, dir, size;
};
int r, c, m, dx[5] = {0, -1, 1, 0, 0}, dy[5] = {0, 0, 0, 1, -1};
int sea[101][101], answer = 0;
sharks shark_state[10001];

void shark_move() {
	queue<int> q;
	for(int i=1; i<=r; i++) for(int j=1; j<=c; j++) {
		if(sea[i][j] != 0) q.push(sea[i][j]);
	}
	int sea_data[101][101];
	memset(sea_data, 0, sizeof(sea_data));
	while(!q.empty()) {
		int num = q.front();
		q.pop();
		int x = shark_state[num].x, y = shark_state[num].y, spd = shark_state[num].speed, direction = shark_state[num].dir, size = shark_state[num].size;
		if(direction == 1 || direction == 2) {
			int left = spd % ((r-1)*2);
			for(int i=0; i<left; i++) {
				if(x == 1) direction = 2;
				if(x == r) direction = 1;
				x += dx[direction];
			}
			if(sea_data[x][y] == 0 ||  shark_state[sea_data[x][y]].size < shark_state[num].size) {
				sea_data[x][y] = num;
				shark_state[num].x = x, shark_state[num].dir = direction;
			}
		}
		else {
			int left = spd % ((c-1)*2);
			for(int i=0; i<left; i++) {
				if(y == 1) direction = 3;
				if(y == c) direction = 4;
				y += dy[direction];
			}
			if(sea_data[x][y] == 0 ||  shark_state[sea_data[x][y]].size < shark_state[num].size) {
				sea_data[x][y] = num;
				shark_state[num].y = y, shark_state[num].dir = direction;
			}
		}
	}
	for(int i=1; i<=r; i++) for(int j=1; j<=c; j++) {
		sea[i][j] = sea_data[i][j];
	}
}

void king_move(int column) {
	for(int i=1; i<=r; i++) {
		if(sea[i][column] != 0) {
			int shark_num = sea[i][column];
			answer += shark_state[shark_num].size;
			sea[i][column] = 0;
			break;
		}
	}
	shark_move();
}

void init() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> r >> c >> m;
	for(int i=1; i<=m; i++) {
		sharks shark;
		cin >> shark.x >> shark.y >> shark.speed >> shark.dir >> shark.size;
		shark_state[i] = shark;
		sea[shark.x][shark.y] = i;
	}
	for(int i=1; i<=c; i++) {
		king_move(i);
	}
}	

int main() {
	init();
	cout << answer << '\n';
}