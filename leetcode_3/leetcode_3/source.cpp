#include <string>
#include <unordered_map>
using namespace std;


// unorderd_map�� �� character�� ������ ��ġ ���. map�� �Էµ��� �ʾҴٸ� ���� ������ ���� ���̰�
// map�� �ԷµǾ��ٸ� �̹� �ߺ��� ���̱� ������ �׶��� ���̸� ����ϰ�
// ���̸� ����ϴ� ù��ġ�� �ߺ��� ������ ���� ��ġ�� ��� map�� ���� ��ġ�� ���� ����Ѵ�.
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