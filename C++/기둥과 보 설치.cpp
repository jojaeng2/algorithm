#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
bool graph[110][110][2];

bool add_bridge(int x, int y, int t) {
    if(t == 0) {
        if(x == 0 || graph[x][y][1] || graph[x][y-1][1] || graph[x-1][y][0]) return true;
    }
    else {
        if(graph[x-1][y][0] || graph[x-1][y+1][0]) return true;
        if(graph[x][y-1][1] && graph[x][y+1][1]) return true;
    }
    
    return false;
}

void del_bridge(int x, int y, int t) {
    graph[x][y][t] = false;
    if(t == 0) {
        if(graph[x+1][y][0]) {
            if(!add_bridge(x+1, y, 0)) {
                graph[x][y][t] = true;
                return;
            }
        }
        if(graph[x+1][y][1]) {
            if(!add_bridge(x+1, y, 1)) {
                graph[x][y][t] = true;
                return;
            }
        }
        if(graph[x+1][y-1][1]) {
            if(!add_bridge(x+1, y-1, 1)) {
                graph[x][y][t] = true;
                return;
            }
        }
    }
    else {
        if(graph[x][y][0]) {
            if(!add_bridge(x, y, 0)) {
                graph[x][y][t] = true;
                return;
            }
        }
        if(graph[x][y+1][0]) {
            if(!add_bridge(x, y+1, 0)) {
                graph[x][y][t] = true;
                return;
            }
        }
        if(graph[x][y-1][1]) {
            if(!add_bridge(x, y-1, 1)) {
                graph[x][y][t] = true;
                return;
            }
        }
        if(graph[x][y+1][1]) {
            if(!add_bridge(x, y+1, 1)) {
                graph[x][y][t] = true;
                return;
            }
        }
    }
}

bool compare(vector<int> a, vector<int> b) {
    if(a[0] == b[0]) {
        if(a[1] == b[1]) {
            return a[2] < b[2];
        }
        return a[1] < b[1];
    }
    return a[0] < b[0];
}


vector<vector<int> > solution(int n, vector<vector<int> > build_frame) {
    vector<vector<int> > answer;
    for(int i=0; i<build_frame.size(); i++) {
        int y = build_frame[i][0], x = build_frame[i][1], t = build_frame[i][2], ord = build_frame[i][3];
        if(ord == 1) {  
            if(add_bridge(x, y+1, t)) graph[x][y+1][t] = true;
        }
        else {
            del_bridge(x, y+1, t);
        }
    }
    for(int i=0; i<=n+1; i++) {
        for(int j=0; j<=n+1; j++) {
            if(graph[i][j][0]) {
                vector<int> v;
                v.push_back(j-1);
                v.push_back(i);
                v.push_back(0);
                answer.push_back(v);
            }
            if(graph[i][j][1]) {
                vector<int> v;
                v.push_back(j-1);
                v.push_back(i);
                v.push_back(1);
                answer.push_back(v);
            }
        }
    }
    sort(answer.begin(), answer.end(), compare);
    return answer;
}