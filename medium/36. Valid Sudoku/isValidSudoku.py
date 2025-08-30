class Solution(object):
    def isValidSudoku(self, board):
        valid = [[[False for i in range(9)] for j in range(9)] for k in range(3)]
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue
                num = ord(board[i][j]) - ord('1')
                if valid[0][i][num] or valid[1][j][num] or valid[2][3 * (i / 3) + j / 3][num]:
                    return False
                valid[0][i][num] = valid[1][j][num] = valid[2][3 * (i / 3) + j / 3][num] = True
        return True