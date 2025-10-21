/* https://school.programmers.co.kr/learn/courses/30/lessons/92344?language=cpp */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//int solution(vector<vector<int>> board, vector<vector<int>> skill) {
//    for (const vector<int>& cnt : skill)
//    {
//        for (int i = cnt[1]; i <= cnt[3]; i++)
//        {
//            for (int j = cnt[2]; j <= cnt[4]; j++)
//            {
//                if(cnt[0] == 1) // 적 공격
//                  board[i][j] -= cnt[5];
//                else if(cnt[0] == 2) // 아군 회복
//                  board[i][j] += cnt[5];
//            }
//        }
//    }
//
//    // 파괴되지 않은 건물 수 계산
//    int answer = 0;
//    for (const vector<int>& row : board)
//    {
//        for (int i = 0; i < row.size(); i++)
//        {
//            if (row[i] >= 1)
//                answer++;
//        }
//    }
//    return answer;
//}


int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    vector<vector<long long>> diff(board.size()+1, vector<long long>(board[0].size() +1, 0));

    // 누적합 연산
    for (const vector<int>& cnt : skill)
    {
        int type = cnt[0];
        int r1 = cnt[1];
        int c1 = cnt[2];
        int r2 = cnt[3];
        int c2 = cnt[4];
        int degree = cnt[5];

        long long d = (type == 1) ? -(long long)degree : (long long)degree;

        diff[r1][c1] += d;
        diff[r1][c2 + 1] -= d;
        diff[r2 + 1][c1] -= d;
        diff[r2 + 1][c2 + 1] += d;
    }

    // 가로 누적 연산
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            diff[i][j+1] += diff[i][j];
        }
    }

    // 세로 누적 연산
    for (int i = 0; i < board[0].size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            diff[j+1][i] += diff[j][i];
        }
    } 

    // 정답 도출
    int answer = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            long long cal = board[i][j] + diff[i][j];
            if (cal >= 1)
                answer++;
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> board = { {5, 5, 5, 5, 5}, {5, 5, 5, 5, 5}, {5, 5, 5, 5, 5}, {5, 5, 5, 5, 5} };
    vector<vector<int>> skill = { {1, 0, 0, 3, 4, 4}, {1, 2, 0, 2, 3, 2}, {2, 1, 0, 3, 1, 2}, {1, 0, 1, 3, 3, 1} };

    cout << solution(board, skill);
};