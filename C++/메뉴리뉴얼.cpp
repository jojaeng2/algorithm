#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
map<string, int> m;
int length[11];


void dfs(vector<char> v, int idx, int cnt, string s) {
    if(cnt>10) return;
    if(m.find(s) == m.end()) m.insert(make_pair(s, 1));
    else m[s] += 1;
    length[s.size()] = max(length[s.size()], m[s]);
    for(int i=idx; i<v.size(); i++) {
        s += v[i];
        dfs(v, i+1, cnt+1, s);
        s.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    memset(length, 0, sizeof(length));
    vector<string> answer;
    for(int i=0; i<orders.size(); i++) {
        vector<char> v;
        for(int j=0; j<orders[i].size(); j++) {
            v.push_back(orders[i][j]);
        }
        sort(v.begin(), v.end());
        dfs(v, 0, 0, "");
    }
    for(int i=0; i<course.size(); i++) {
        for(map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
            if(iter->first.size() == course[i] && iter->second == length[course[i]] && iter->second>=2) answer.push_back(iter->first);
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}