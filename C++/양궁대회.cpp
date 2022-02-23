#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#define X first
#define Y second
using namespace std;
map<int, vector<vector<int>>> mp;
vector<int> v;
int maxi = -1;

bool compare(vector<int> a, vector<int> b) {
    for(int i=a.size()-1; i>=0; i--) {
        if(a[i] == b[i]) continue;
        return a[i] > b[i];
    }
} 

void dfs(int s, vector<int>& info, int cnt, int a, int b, int idx) {
    if(idx == 11) {
        if(a <= b) return;
        maxi = max(maxi, a-b);
        int t = v.back();
        v.pop_back();
        v.push_back(t + s-cnt);
        mp[a-b].push_back(v);
        return;
    }
    if(info[idx]) {
        if(s >= info[idx] + cnt+1) {
            v.push_back(info[idx]+1);
            dfs(s, info, cnt + info[idx]+1, a+10-idx, b, idx+1);
            v.pop_back();
        }
        v.push_back(0);
        dfs(s, info, cnt, a, b+10-idx, idx+1);
        v.pop_back();
    }
    else {
        if(s >= cnt+1) {
            v.push_back(1);
            dfs(s, info, cnt+1, a+10-idx, b, idx+1);
            v.pop_back();
        }
        v.push_back(0);
        dfs(s, info, cnt, a, b, idx+1);
        v.pop_back();
    }
}

vector<int> solution(int n, vector<int> info) {
    dfs(n, info, 0, 0, 0, 0);
    vector<int> answer;
    if(maxi == -1) return {-1};
    else {
        sort(mp[maxi].begin(), mp[maxi].end(), compare);
        answer = mp[maxi][0];
        return answer;
    }
}