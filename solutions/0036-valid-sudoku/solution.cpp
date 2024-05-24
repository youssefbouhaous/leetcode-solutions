class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            set<char>st;
            //cout<<endl;
            for(int j=0;j<board.size();j++){
                //cout<<board[i][j];
                if(board[i][j]!='.' && st.count(board[i][j])){
                    return false;
                }
             
                    st.insert(board[i][j]);
                
            }
        }
        for(int i=0;i<board.size();i++){
            set<char>st;
            for(int j=0;j<board.size();j++){
                if(board[j][i]!='.' && st.count(board[j][i])){
                    //cout<<"here";
                    return false;
                }
                st.insert(board[j][i]);
                
            }
        }
        vector<pair<int,int>>com={{0,2},{3,5},{6,8}};
        for(auto px:com){
            for(auto py:com){
                set<char>st;
                for(int i=px.first;i<=px.second;i++){
                    for(int j=py.first;j<=py.second;j++){
                        if( board[i][j]!='.' && st.count(board[i][j])){
                            //cout<<"here";
                            return false;
                        }
                        st.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};