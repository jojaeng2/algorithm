#include <iostream>
using namespace std;
int green[4][6], blue[4][6], n, answer = 0;

void print() {
    int cnt = 0;
    for(int i=0; i<4; i++) {
        for(int j=0; j<6; j++) {
            if(blue[i][j]==1) cnt++;
            if(green[i][j]==1) cnt++;
        }
    }
    cout << answer << '\n' << cnt << '\n';
}

void rm_over(int graph[4][6]) {
    int cnt = 0;
    for(int i=0; i<2; i++) {
        if(graph[0][i] == 1 || graph[1][i] == 1 || graph[2][i] == 1 || graph[3][i] == 1) cnt++;
    }
    for(int i=5; i>0; i--) {
        graph[0][i] = graph[0][i-cnt], graph[1][i] = graph[1][i-cnt], graph[2][i] = graph[2][i-cnt], graph[3][i] = graph[3][i-cnt];
    }
    for(int i=0; i<cnt; i++) {
        graph[0][i] = 0, graph[1][i] = 0, graph[2][i] = 0, graph[3][i] = 0;
    }
}

void score(int graph[4][6]) {
    for(int i=5; i>0; i--) {
        if(graph[0][i]==1 && graph[1][i] == 1 && graph[2][i] == 1 && graph[3][i] == 1) {
            while(true) {
                if(graph[0][i]!=1 || graph[1][i] != 1 || graph[2][i] != 1 || graph[3][i] != 1) break;
                answer++;
                for(int j=i; j>0; j--) {
                    graph[0][j] = graph[0][j-1], graph[1][j] = graph[1][j-1], graph[2][j] = graph[2][j-1], graph[3][j] = graph[3][j-1];
                }
            }
        }
    }
}
void move_blocks(int graph[4][6], int t, int x, int y) {
    if(t == 1) {
        for(int i=0; i<6; i++) {
            if(graph[x][i] == 1) {
                graph[x][i-1] = 1;
                break;
            }
            else if(i==5) graph[x][i] = 1;
        }
    }
    else if(t == 2) {
        for(int i=0; i<6; i++) {
            if(graph[x][i] == 1) {
                graph[x][i-1] = 1, graph[x][i-2] = 1;
                break;
            }
            else if(i==5) graph[x][i] = 1, graph[x][i-1] = 1;
        }
    }
    else {
        for(int i=0; i<6; i++) {
            if(graph[x][i] == 1 || graph[x+1][i] == 1) {
                graph[x][i-1] = 1, graph[x+1][i-1] = 1;
                break;
            }
            else if(i==5) graph[x][i] = 1, graph[x+1][i] = 1;
        }
    }
}

void init() {
    cin >> n;
    while(n--) {
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1) {
            move_blocks(green, 1, y, x);
            move_blocks(blue, 1, x, y);
        }
        else if(t == 2) {
            move_blocks(green, 3, y, x);
            move_blocks(blue, 2, x, y);
        }
        else {
            move_blocks(green, 2, y, x);
            move_blocks(blue, 3, x, y);
        }
        score(green), score(blue);
        rm_over(green), rm_over(blue);
    }   
}

int main() {
    init();
    print();
}