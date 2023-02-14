#include <string>
#include <unordered_map>
using namespace std;


// unorderd_map에 각 character의 마지막 위치 기록. map에 입력되지 않았다면 아직 나오지 않을 것이고
// map에 입력되었다면 이미 중복된 것이기 때문에 그때의 길이를 기록하고
// 길이를 기록하는 첫위치를 중복된 글자의 다음 위치로 잡고 map에 현재 위치를 새로 기록한다.
class Solution
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        if (s.empty())
            return 0;
        unordered_map<char, int> lastPos;
        int currentIdx,startIdx = 0, answer = 1;
        for (currentIdx = 0; currentIdx < s.size(); ++currentIdx)
        {
            if (lastPos.find(s[currentIdx]) !=lastPos.end() && lastPos[s[currentIdx]]>=startIdx)
            {
                answer = max(answer, currentIdx - startIdx);
                startIdx = lastPos[s[currentIdx]]+1;
                lastPos[s[currentIdx]] = currentIdx;
            }
            else
            {
                lastPos[s[currentIdx]] = currentIdx;
            }
        }
        answer = max(answer, currentIdx - startIdx);
        return answer;
    }
};


int main()
{
    Solution s;
    s.lengthOfLongestSubstring("");
}