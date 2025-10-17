/* https://school.programmers.co.kr/learn/courses/30/lessons/181188#qna */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// a �� b �� end �������� ��
bool compare(const vector<int>& a, const vector<int>& b)
{
    return a.back() < b.back();
}

int solution(vector<vector<int>> targets) {
    int answer = 0;

    // ���� �� end �������� �������� ����
    sort(targets.begin(), targets.end(), compare);

    // ù ����� ������ last�� ����
    // ���� ������ start�� ���� last���� ������ ���� ������� ó��
    // ũ�� �� ������� ó��, answer +1, last ��ü
    int last = INT_MIN;
    for (const vector<int>& target : targets)
    {
        int back = target.front();
        if (last <= back)    // �� ��� ó��
        {
            last = target.back();
            answer++;
        }
        else continue;      // ���� ��� ó��
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