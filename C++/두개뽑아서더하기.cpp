#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
set<int> st;
bool visit[110] = {false};


void dfs(int s, int e, vector<int> nums, int psum) {
    if(s == e) {
        if(st.find(psum) == st.end()) st.insert(psum);
        return;
    }
    for(int i=0; i<nums.size(); i++) {
        if(visit[i]) continue;
        visit[i] = true;
        dfs(s+1, e, nums, psum + nums[i]);
        visit[i] = false;
    }
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    dfs(0, 2, numbers, 0);
    for(auto ss : st) {
        answer.push_back(ss);
    }
    sort(answer.begin(), answer.end());
    return answer;
}