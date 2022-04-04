#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int DP[510][510];

int solution(vector<vector<int>> triangle) {
    memset(DP, 0, sizeof(DP));
    int answer = 0;
    DP[0][0] = triangle[0][0];
    for(int i=0; i<triangle.size()-1; i++) {
        for(int j=0; j<triangle[i].size(); j++) {
            DP[i+1][j] = max(DP[i+1][j], DP[i][j] + triangle[i+1][j]);
            DP[i+1][j+1] = max(DP[i+1][j+1], DP[i][j] + triangle[i+1][j+1]);
            answer = max({answer, DP[i+1][j], DP[i+1][j+1]});
        }
    }
    return answer;
}