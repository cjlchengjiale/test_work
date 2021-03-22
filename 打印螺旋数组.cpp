class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int on = 0,right = matrix[0].size() - 1;
        int left = 0,down = matrix.size() - 1;
        int sum = (right + 1) * (down + 1);
        int i = 0,j = 0;
        while(res.size() <sum)
        {
            if(j == left && i == on)
            {
                while(j <= right)   res.push_back(matrix[i][j++]);
                j--;
                on++;
                i++;
            }
            else if(j == right && i == on)
            {
                while(i <= down)    res.push_back(matrix[i++][j]);
                i--;
                right--;
                j--;
            }
            else if(i == down && j == right)
            {
                while(j >= left)    res.push_back(matrix[i][j--]);
                j++;
                down--;
                i--;
            }
            else if(i == down && j == left)
            {
                while(i >= on)  res.push_back(matrix[i--][j]);
                i++;
                j++;
                left++;
            }
        }
        return res;
    }
};
