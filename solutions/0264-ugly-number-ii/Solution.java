class Solution {
    public int nthUglyNumber(int n) {
        List<Integer>l= new ArrayList<>();
        for(int a=0;a<=30;a++)
        for(int b=0;b<=20;b++)
        for(int c=0;c<=20;c++) l.add((int)(Math.pow(2,a)*Math.pow(3,b)*Math.pow(5,c)));
        Collections.sort(l);
        return l.get(n-1);
    }
}