class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool valid[3][9][9] = {{{false}}};
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '1';
                if (valid[0][i][num] || valid[1][j][num] || valid[2][3 * (i / 3) + j / 3][num])
                    return false;
                valid[0][i][num] = valid[1][j][num] = valid[2][3 * (i / 3) + j / 3][num] = true;
            }
        return true;
    }
};