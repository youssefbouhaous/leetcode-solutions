class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& p) {
        int n=p.size();
        int ans=-1;
        sort(p.begin(),p.end());
        for(int i=0;i<n;i++){
            int x,y;
            int x1=p[i][0];int y1=p[i][1];
            int x2=102;int y2=p[i][1];
            int x3=p[i][0];int y3=102;
            int x4=-1;int y4=-1;
            for(int j=i+1;j<n;j++){
                if(p[j][1]>=p[i][1]){
                if(p[j][1]==y1 && p[j][0]!=x1){
                    x2=min(p[j][0],x2);
                }
                if(p[j][0]==x1 && p[j][1]!=y2){
                    y3=min(p[j][1],y3);
                }
                }
            }
            
            if(x2!=102 && y3!=102){
                x4=x2;y4=y3;/*
                cout<<x1<<" - "<<y1<<endl;
                cout<<x2<<" - "<<y2<<endl;
                cout<<x3<<" - "<<y3<<endl;
                cout<<x4<<" - "<<y4<<endl;
                cout<<"/******************\n";*/
                
                set<pair<int,int>>st={{x1,y1},{x2,y2},{x3,y3},{x4,y4}};
                bool f=false;
                for(int u=0;u<n;u++){
                    if(p[u][0]==x4 && p[u][1]==y4){
                        f=true;
                        break;
                    }
                }
                        for(int u=0;u<n && f;u++){
                            if(st.count({p[u][0],p[u][1]})==0){
                                if(p[u][0]>=min(x1,x2) && p[u][0]<=max(x1,x2) && p[u][1]<=max(y1,y3) && p[u][1]>=min(y1,y3)){
                                    f=false;
                                }
                            }
                        }
                    /*
                for(int k=min(x1,x2)+1;k<=max(x1,x2)-1 && f;k++){
                    for(int u=0;u<n && f;u++){
                            if(st.count({p[u][0],p[u][1]})==0){
                                if(p[u][0]>min(x1,x2) && p[u][0]<max(x1,x2) && p[u][1]<max(y1,y3) && p[u][1]>min(y1,y3)){
                                    f=false;
                                }
                            }
                    }
                }*/
                if(f){
                    ans=max(ans,abs(x1-x2)*abs(y1-y3));
                }
            }
        }
        return ans;
    }
};