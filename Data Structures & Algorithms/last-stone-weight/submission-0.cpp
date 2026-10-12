class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stoner;
        for(auto val:stones)
            stoner.push(val);
        int answer = 0;
        while(stoner.size() > 1){
            // extract top two stones
            int first = stoner.top();
            stoner.pop();
            int second = stoner.top();
            stoner.pop();
            // insert difference if exists
            if (first == second)
                continue;
            stoner.push(abs(first - second));
        }
        if(stoner.size() == 1)
            return stoner.top();
        return 0;
    }
};
