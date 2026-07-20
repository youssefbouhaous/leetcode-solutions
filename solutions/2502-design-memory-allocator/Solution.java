class Allocator {
    int[] mem;
    int n;
    public Allocator(int n) {
        mem = new int[n];
        this.n = n;
    }
    
    public int allocate(int size, int mID) {
        int l=0;
        int r=0;
        int ans=-1;
        loop1:while(r<n && l<n){
            if(mem[l]==0){
                r=l;
                while(r<n&&mem[r]==0){
                    r++;
                }
                if(r-l>=size){
                    ans=l;
                    break loop1;
                }else{
                    l=r+1;
                }
            }else{
                l++;
            }
        }
        if(ans==-1)return -1;
        else{
            int i=ans;
            while(size>0){
                mem[i]=mID;i++;size--;
            }
            return ans;
        }
    }
    
    public int freeMemory(int mID) {
        int cnt=0;
        for(int i=0;i<n;i++){
            if(mem[i]==mID){
                mem[i]=0;cnt++;}
        }
        return cnt;
    }
}

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator obj = new Allocator(n);
 * int param_1 = obj.allocate(size,mID);
 * int param_2 = obj.freeMemory(mID);
 */