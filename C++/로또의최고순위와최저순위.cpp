#include <string>
#include <vector>
#include <map>
using namespace std;
map<int, int> mp;


vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt = 0;
    for(int lo : lottos) mp[lo]++;
    for(int win : win_nums) {
        if(mp[win] != 0) cnt++;
    }
    int maxi = cnt + mp[0];
    if(maxi == 6) answer.push_back(1);
    else if(maxi == 5) answer.push_back(2);
    else if(maxi == 4) answer.push_back(3);
    else if(maxi == 3) answer.push_back(4);
    else if(maxi == 2) answer.push_back(5);
    else answer.push_back(6);
    
    if(cnt == 6) answer.push_back(1);
    else if(cnt == 5) answer.push_back(2);
    else if(cnt == 4) answer.push_back(3);
    else if(cnt == 3) answer.push_back(4);
    else if(cnt == 2) answer.push_back(5);
    else answer.push_back(6);
    
    return answer;
}