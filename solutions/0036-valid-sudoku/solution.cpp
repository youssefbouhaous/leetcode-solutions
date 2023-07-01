class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        string d="123456789";
        for(int i=0;i<9;i++){
            for(auto x:d){
                if(count(board[i].begin(),board[i].end(),x)>1){
                    return 0;
                }
            }
        }
        for(int i=0;i<9;i++){
            vector<char>a;
            for(int j=0;j<9;j++){
                a.push_back(board[j][i]);
            }
            for(auto x:d){
                if(count(a.begin(),a.end(),x)>1){
                    return 0;
                }
            }
        }
        for(int i=2;i<9;i+=3){
            for(int j=2;j<9;j+=3){
                vector<char>a;
                for(int l=i-2;l<=i;l++){
                    for(int c=j-2;c<=j;c++){
                        a.push_back(board[l][c]);
                    }
                }
                for(auto x:d){
                    if(count(a.begin(),a.end(),x)>1){
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
};