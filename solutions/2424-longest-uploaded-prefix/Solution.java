class LUPrefix {
// 0 -> id
// arr 1 0 1 0 0 1
// pre[i] = pre[i-1] + arr[i] 
    private int[] pre;
    private int last;
    public LUPrefix(int n) {
        pre = new int[n];
        last = 0;
    }
    
    public void upload(int video) {
        pre[video-1] = 1;
        if(video-1 == last){
            while(last<pre.length && pre[last]==1){
                last++;
            }
        }
    }
    // 1 1 1 n 1 n 1
    public int longest() {
        return last;
    }
}

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix obj = new LUPrefix(n);
 * obj.upload(video);
 * int param_2 = obj.longest();
 */