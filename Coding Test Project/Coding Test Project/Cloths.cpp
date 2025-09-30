/* https://school.programmers.co.kr/learn/courses/30/lessons/42578 */

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> category;

    // �� ���� �� �з�
    for(vector<string> cloth : clothes)
    {
        string key = cloth.back();
        // �� �׸��̶��
        if (category.find(key) == category.end())
        {
            // �� �׸� 1 + ���Դ´ٴ� ���̽� 1 = 2
            category.insert(make_pair(key, 2));
        }
        // ������ �ִ� �׸��̶��
        else category[key]++;
    }

    int answer = 1;
    for (pair<string, int> cnt : category)
    {
        answer *= cnt.second;
    }
    answer--;
    return answer;
}

int main()
{
    vector<vector<string>> clothes = { {"circle_glasses", "face"}, {"black_sunglasses", "face"}, {"blue_shrit", "shrit"}, {"blue_jeans", "jeans"}, {"long_cort", "cort"}};
    cout << solution(clothes);

    return 0;
}