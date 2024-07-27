class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int b,w;
        b=0;w=0;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                if(grid[i][j]=='B')
                    b++;
                else 
                    w++;
            }
        }
        if(b>2 || w>2){
            return true;
        }
        b=0;w=0;
        for(int i=1;i<3;i++){
            for(int j=0;j<2;j++){
                if(grid[i][j]=='B')
                    b++;
                else 
                    w++;
            }
        }
        if(b>2 || w>2){
            return true;
        }
        b=0;w=0;
        for(int i=0;i<2;i++){
            for(int j=1;j<3;j++){
                if(grid[i][j]=='B')
                    b++;
                else 
                    w++;
            }
        }
        if(b>2 || w>2){
            return true;
        }
        b=0;w=0;
        for(int i=1;i<3;i++){
            for(int j=1;j<3;j++){
                if(grid[i][j]=='B')
                    b++;
                else 
                    w++;
            }
        }
        if(b>2 || w>2){
            return true;
        }
        return false;
    }
};