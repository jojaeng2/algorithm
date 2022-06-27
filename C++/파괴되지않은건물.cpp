#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
int psum[1010][1010];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    memset(psum, 0, sizeof(psum));
    int answer = 0;
    for(auto sk : skill) {
        int type = sk[0], r1 = sk[1]+1, c1 = sk[2]+1, r2 = sk[3]+1, c2 = sk[4]+1, degree = sk[5];
        if(type == 1) degree = -degree;
        psum[r1][c1] += degree, psum[r1][c2+1] -= degree, psum[r2+1][c1] -= degree, psum[r2+1][c2+1] += degree;
    }
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++) {
            psum[i+1][j+1] += psum[i][j+1] + psum[i+1][j] - psum[i][j];
        }
    }
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++) {
            if(psum[i+1][j+1] + board[i][j] > 0) answer++;
        }
    }
    return answer;
}