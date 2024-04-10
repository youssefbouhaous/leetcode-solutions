class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int t) {
        int a=0;
        int b=matrix.size()-1;
        int m=b;
        int n=matrix[0].size()-1;
        while(a<=b){
            int my=(a+b)/2;
            if(matrix[my][n]>=t && matrix[my][0]<=t){
                int l=0;
                int r=n;
                while(l<=r){
                    int mx=(l+r)/2;
                    if(matrix[my][mx]==t){
                        return true;
                    }
                    else if(matrix[my][mx]<t){
                        l++;
                    }
                    else{
                        r--;
                    }
                }
                return false;
            }
            else if(matrix[my][n]<t){
                a++;
            }
            else{
                b--;
            }
        }
        return false;
    }
};