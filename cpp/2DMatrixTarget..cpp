---------------------------------------------
  You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
--------------------------------------------------------
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if ((target < matrix[0][0]) ||
            (target > matrix[matrix.size()-1][matrix[0].size()-1])) {
           return false;
        }
        if ((target == matrix[0][0]) ||
            (target == matrix[matrix.size()-1][matrix[0].size()-1])) {
           return true;
        }
        int srow=0;
        int erow=matrix.size()-1;
        int mid=(srow+erow)/2;
        while(erow >= srow)
        {
            if (target < matrix[mid][0]) {
                erow=mid-1;
            } else if (target > matrix[mid][0]) {
                srow=mid+1;
            } else {
                return true;
            }
            {
                int scol=0;
                int ecol=matrix[0].size()-1;
                int mid1=(scol+ecol)/2;
                while(ecol >= scol)
                {
                    if (target < matrix[mid][mid1]) 
                    {
                        ecol=mid1-1;
                    } else  if (target > matrix[mid][mid1]) {
                        scol=mid1+1;
                    } else {
                        return true;
                    }
                    mid1=(scol+ecol)/2;
                }
            }
            mid=(srow+erow)/2;
        }
        return false;
    }
};
