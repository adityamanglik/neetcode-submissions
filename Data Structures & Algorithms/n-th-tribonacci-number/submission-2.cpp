class Solution {
public:
    int tribo(unordered_map<int, int> &memo, int n){
        if(n == 0)
            return 0;
        if(n == 1 or n == 2)
            return 1;
        if(memo.find(n) != memo.end())
            return memo[n];
        memo[n] = tribo(memo, n-1) + tribo(memo, n-2) + tribo(memo, n-3);
        return memo[n];
    }
    int tribonacci(int n) {
        unordered_map<int, int> memo;
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;
        return tribo(memo, n);
    }
};