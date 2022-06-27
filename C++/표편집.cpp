#include <string>
#include <vector>
#include <iostream>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
pii link[1000010];
bool visit[1000010] = {false};
vector<int> idx;

void init(int n) {
    for(int i=0; i<n; i++) {
        if(i == 0) {
            link[i].X = i+1;
            link[i].Y = -1;
        }
        else if(i == n-1) {
            link[i].X = -1;
            link[i].Y = i-1;
        }
        else {
            link[i].X = i+1;
            link[i].Y = i-1;
        }
    }
}


string solution(int n, int k, vector<string> cmd) {
    init(n);
    for(int i=0; i<cmd.size(); i++) {
        string s = cmd[i];
        if(s[0] == 'C') {
            visit[k] = true;
            idx.push_back(k);
            if(link[k].X == -1) {
                link[link[k].Y].X = -1;
                k = link[k].Y;
            }
            else if(link[k].Y == -1) {
                link[link[k].X].Y = -1;
                k = link[k].X;
            }
            else {
                link[link[k].X].Y = link[k].Y;
                link[link[k].Y].X = link[k].X;
                k = link[k].X;
            }
        }
        if(s[0] == 'Z') {
            int deleted = idx.back();
            idx.pop_back();
            visit[deleted] = false;
            if(link[deleted].X == -1) {
                link[link[deleted].Y].X = deleted;   
            }
            else if(link[deleted].Y == -1) {
                link[link[deleted].X].Y = deleted;
                
            }
            else {
                link[deleted].X = link[link[deleted].Y].X;
                link[deleted].Y = link[link[deleted].X].Y;
                link[link[deleted].X].Y = deleted;
                link[link[deleted].Y].X = deleted;
            }
        }
        if(s[0] == 'U') {
            int cnt = stoi(s.substr(2, s.size()));
            while(cnt--) k = link[k].Y;
        }
        if(s[0] == 'D') {
            int cnt = stoi(s.substr(2, s.size()));
            while(cnt--) k = link[k].X;
        }
    }
    
    string answer = "";
    for(int i=0; i<n; i++) {
        if(!visit[i]) answer += 'O';
        else answer += 'X';
    }
    return answer;
}

int main() {
    vector<string> v;
    v.push_back("D 2");
    v.push_back("C");
    v.push_back("U 3");

    v.push_back("C");

    v.push_back("D 4");

    v.push_back("C");

    v.push_back("U 2");

    v.push_back("Z");
    v.push_back("Z");

    v.push_back("U 1");

    v.push_back("C");
    cout << solution(3, 1, v) << '\n';
}