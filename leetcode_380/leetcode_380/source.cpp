#include <unordered_set>
#include <ctime>
using namespace std;

class RandomizedSet 
{
public:
    RandomizedSet() 
    {
        seed = (unsigned int)time(NULL);
        srand(seed);
    }

    bool insert(int val) 
    {
        if (set.end() == set.find(val))
        {
            set.insert(val);
            return true;
        }
        else
        {
            return false;
        }
    }

    bool remove(int val) 
    {
        if (set.end() == set.find(val))
        {
            return false;
        }
        else
        {
            set.erase(val);
            return true;
        }
    }

    int getRandom() 
    {
        int randIdx = rand();
        int end = randIdx % set.size();
        auto iter = set.begin();
        for (int i = 0; i < end; ++i)
            iter++;
        return *iter;
    }

public:
    unordered_set<int> set;
    unsigned int seed;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */