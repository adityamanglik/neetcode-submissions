class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int i = 0;
        int j = 1;

        while(i < prices.size() and j < prices.size()){
            if(prices[i] > prices[j]){
                i=j;
                j++;
            }
            else if(prices[i] == prices[j]){
                j++;
            }
            else if(prices[i] < prices[j]){
                if(prices[j] - prices[i] > profit)
                    profit = prices[j] - prices[i];
                j++;
            }
        }
        return profit;
    }
};
