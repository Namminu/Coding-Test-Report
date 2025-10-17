/* https://school.programmers.co.kr/learn/courses/30/lessons/181188#qna */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// a 와 b 의 end 오름차순 비교
bool compare(const vector<int>& a, const vector<int>& b)
{
    return a.back() < b.back();
}

int solution(vector<vector<int>> targets) {
    int answer = 0;

    // 구간 별 end 기준으로 오름차순 정렬
    sort(targets.begin(), targets.end(), compare);

    // 첫 요격의 끝점을 last로 지정
    // 다음 구간의 start가 이전 last보다 작으면 같은 요격으로 처리
    // 크면 새 요격으로 처리, answer +1, last 교체
    int last = INT_MIN;
    for (const vector<int>& target : targets)
    {
        int back = target.front();
        if (last <= back)    // 새 요격 처리
        {
            last = target.back();
            answer++;
        }
        else continue;      // 같은 요격 처리
    }

    return answer;
}

int main()
{
    vector<vector<int>> targets = { {4, 5}, {4, 8}, {10, 14}, {11, 13}, {5, 12}, {3, 7}, {1, 4} };
    cout << solution(targets);

    return 0;
}

/*
4 5 / 4 8 / 10 14 / 11 13 / 5 12 / 3 7 / 1 4

1 4 / 4 5 / 3 7 / 4 8 / 5 12 / 11 13 / 10 14

1   / 2               / 3                    

*/