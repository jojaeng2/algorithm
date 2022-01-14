#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;
int in[1010], cnt = 1, ans[1010];
bool visit[1010][1010];
vector<string> adj[1010];
map<string, int> mp;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    memset(visit, false, sizeof(visit));
    memset(in, 0, sizeof(in));
    memset(ans, 0, sizeof(ans));
    vector<int> answer;
    for(auto id : id_list) mp[id] = cnt++;
    for(auto port : report) {
        vector<string> res = split(port, ' ');
        string s1 = res[0], s2 = res[1];
        if(visit[mp[s1]][mp[s2]]) continue;
        visit[mp[s1]][mp[s2]] = true;
        in[mp[s2]]++;
        adj[mp[s2]].push_back(s1);
    }
    for(auto str : id_list) {
        if(in[mp[str]] >= k) {
            for(auto next : adj[mp[str]]) {
                ans[mp[next]]++;
            }
        }
    }
    for(auto str : id_list) answer.push_back(ans[mp[str]]);
    return answer;
}