/* https://school.programmers.co.kr/learn/courses/30/lessons/43165 */

#include <vector>
#include <iostream>

using namespace std;
int answer = 0;

void method(const vector<int>& numbers, int i, int sum, const int& target)
{
    if (i == numbers.size())
    {
        if (sum == target)
            answer++;
        return;
    }

    method(numbers, i + 1, sum + numbers[i], target);
    method(numbers, i + 1, sum - numbers[i], target);
}

int solution(vector<int> numbers, int target) {
    method(numbers, 0, 0, target);
    return answer;
}

int main()
{
    vector<int> numbers = {1, 1, 1, 1, 1};
    int target = 3;
    cout << solution(numbers, target);

    return 0;
}