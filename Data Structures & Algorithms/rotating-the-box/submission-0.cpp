class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        //Brute force approach

    int ROWS = boxGrid.size(), COLS = boxGrid[0].size();
//For each row, iterate from right to left.

        for (int r = ROWS - 1; r >= 0; r--) {
            for (int c1 = COLS - 1; c1 >= 0; c1--) {
                if (boxGrid[r][c1] == '#') {
                    //When a stone # is found, scan rightward to find the farthest empty cell . before hitting an obstacle * or boundary.
                    //Move the stone to that position.
                    int c2 = c1 + 1;
                    while (c2 < COLS && boxGrid[r][c2] == '.') {
                        c2++;
                    }
                    boxGrid[r][c1] = '.';
                    boxGrid[r][c2 - 1] = '#';
                }
            }
        }
        
//After processing all rows, create the rotated grid:
//The new grid has COLS for rows and ROWS for columns.
        vector<vector<char>> res(COLS, vector<char>(ROWS));
        for (int c = 0; c < COLS; c++) {
            for (int r = ROWS - 1; r >= 0; r--) {
                //For each column c in the original grid, the new row at index c contains elements from bottom to top of that column.
                res[c][ROWS - 1 - r] = boxGrid[r][c];
            }
        }
        //Return the rotated grid.

        return res;
    }
};