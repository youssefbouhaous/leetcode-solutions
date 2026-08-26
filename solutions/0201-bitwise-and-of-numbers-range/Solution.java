class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        StringBuilder a = new StringBuilder(Integer.toBinaryString(left));
        StringBuilder b = new StringBuilder(Integer.toBinaryString(right));
        StringBuilder aa = new StringBuilder();
        StringBuilder bb = new StringBuilder();
        int n = a.length();
        int m = b.length();
        while(aa.length()+n<32){
            aa.append('0');
        }
        while(bb.length()+m<32){
            bb.append('0');
        }
        aa.append(a);
        bb.append(b);
        StringBuilder ans=new StringBuilder();
        for(int i=0;i<32;i++){
            if(aa.charAt(i)!=bb.charAt(i))break;
            ans.append(aa.charAt(i));
        }
        while(ans.length()<32)ans.append('0');
        return Integer.parseInt(ans.toString(),2);
    }
}