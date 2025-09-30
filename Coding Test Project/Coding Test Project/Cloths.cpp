/* https://school.programmers.co.kr/learn/courses/30/lessons/42578 */

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> category;

    // 옷 종류 별 분류
    for(vector<string> cloth : clothes)
    {
        string key = cloth.back();
        // 새 항목이라면
        if (category.find(key) == category.end())
        {
            // 새 항목 1 + 안입는다는 케이스 1 = 2
            category.insert(make_pair(key, 2));
        }
        // 기존에 있는 항목이라면
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