#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
int n, height[51][51], post_x, post_y, home_cnt = 0, answer = 1000001;
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
char graph[51][51];
vector<int> vh;

bool dfs(int left, int right) {
    if(height[post_x][post_y]<vh[left] || height[post_x][post_y]>vh[right]) return false;
    bool visit[51][51] = {false};
    int cnt = 0;
    stack<pii> stak;
    stak.push(make_pair(post_x, post_y));
    visit[post_x][post_y] = true;
    while(!stak.empty()) {
        int x = stak.top().X, y = stak.top().Y;
        stak.pop();
        for(int i=0; i<8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(1>nx || nx>n || 1>ny || ny>n || visit[nx][ny]) continue;
            if(vh[left]>height[nx][ny] || vh[right]<height[nx][ny]) continue;
            if(graph[nx][ny] == 'K') cnt++;
            visit[nx][ny] = true;
            stak.push(make_pair(nx, ny));
        }
    }
    if(cnt == home_cnt) return true;
    return false;
}


void two_pointer() {
    int left = 0, right = 0;
    while(left <= right && right<=vh.size()-1) {
        if(!dfs(left, right)) right++;
        else {
            answer = min(answer, vh[right]-vh[left]);
            left++;
        }
    }
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<n; j++) {
            graph[i][j+1] = s[j];
            if(graph[i][j+1] == 'P') {
                post_x = i, post_y = j+1;
            }
            else if(graph[i][j+1] == 'K') {
                home_cnt++;
            }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> height[i][j];
            vh.push_back(height[i][j]);
        }
    }
    sort(vh.begin(), vh.end());
}

int main() {
    init();
    two_pointer();
    cout << answer << '\n';
}