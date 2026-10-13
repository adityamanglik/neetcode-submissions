class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows
        for(int i = 0; i < board.size(); ++i){
            set<char> counter;
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == '.')
                    continue;
                if(counter.find(board[i][j]) == counter.end())
                    counter.insert(board[i][j]);
                else
                    return false;
            }
        }
        // check cols
        for(int j = 0; j < board[0].size(); ++j){
            set<char> counter;
            for(int i = 0; i < board.size(); ++i){
                if(board[i][j] == '.')
                    continue;
                if(counter.find(board[i][j]) == counter.end())
                    counter.insert(board[i][j]);
                else
                    return false;
            }
        }
        // check tile
        for(int x = 0; x < 3; ++x)
            for(int y = 0; y < 3; ++y){
                set<char> counter;
                for(int i = x*3; i < x*3 + 3; ++i)
                    for(int j = y*3; j < y*3 + 3; ++j){
                        if(board[i][j] == '.')
                            continue;
                        if(counter.find(board[i][j]) == counter.end())
                            counter.insert(board[i][j]);
                        else
                            return false;
                    }
        }
        return true;
    }
};
