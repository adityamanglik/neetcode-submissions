class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows(matrix.size(), 0);
        vector<int> cols(matrix[0].size(), 0);
        // scan rows
        for(int i = 0; i < rows.size(); ++i)
            for(int j = 0; j < cols.size(); ++j){
                if(matrix[i][j] == 0){
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        // set rows to zero
        for(int i = 0; i < rows.size(); ++i){
            if(rows[i])
                fill(matrix[i].begin(), matrix[i].end(), 0);
        }        
        // set cols to zero
        for(int j = 0; j < cols.size(); ++j){
            if(cols[j])
                for(int i = 0; i < rows.size(); ++i){
                    matrix[i][j] = 0;
                }
        }
        return;
    }
};
