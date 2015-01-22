class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty() || target<matrix[0][0])   return false;
        int i=0, j=matrix.size()-1;
        while(i<j){
            int m=(i+j)/2;
            if(matrix[m][0]==target)    return true;
            if(matrix[m][0]>target)
                j=m-1;
            else
                i=m+1;
        }
        if(matrix[i][0]>target) --i;
        int x=0, y=matrix[0].size()-1;
        while(x<=y){
            int m=(x+y)/2;
            if(matrix[i][m]==target)    return true;
            if(matrix[i][m]>target)
                y=m-1;
            else
                x=m+1;
        }
        return false;
    }
};
