#include <string>
#include <vector>
#include <deque>
#include <queue>
#define X first
#define Y second
using namespace std;
priority_queue<int> pq;
deque<pair<int, int>> dq;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    for(int i=0; i<priorities.size(); i++) {
        dq.push_back({priorities[i], i});
        pq.push(priorities[i]);
    }
    while(!dq.empty()) {
        auto curr = dq.front();
        dq.pop_front();
        int top = pq.top();
        if(curr.X == top) {
            answer++;
            pq.pop();
            if(curr.Y == location) break;
        }
        else dq.push_back(curr);
    }
    return answer;
}