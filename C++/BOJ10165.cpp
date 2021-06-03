#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct roads {
    int x, y, idx;
};
int n, m;
bool visit[500001] = {false};
vector<roads> bus;

void print() {
    for(int i=0 ;i<=m; i++) {
        if(visit[i]) {
            cout << i << " ";
        }
    }
    cout << '\n';
}

void greedy() {
    int now = bus.front().idx, r = bus.front().y;
    visit[now] = true;
    for(int i=1; i<bus.size(); i++) {
        int next = bus[i].idx, nr = bus[i].y;
        if(r<nr) {
            r = nr;
            visit[next] = true;
        }
    }
}


bool compare(roads a, roads b) {
    if(a.x == b.x) return a.y > b.y;
    return a.x < b.x; 
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y;
        roads road;
        road.x = x, road.y = y, road.idx = i;
        if(x>y) {
            road.x -= n;
            bus.push_back(road);
            road.x += n, road.y += n;
            bus.push_back(road);
        }
        else bus.push_back(road);
    }
    sort(bus.begin(), bus.end(), compare);
}

int main() {
    init();
    greedy();
    print();
}