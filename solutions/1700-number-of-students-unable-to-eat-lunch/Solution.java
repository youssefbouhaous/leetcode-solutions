class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int cost = 0;
        int cosa = 0;
        int czst = 0;
        int czsa = 0;
        int n = students.length;
        int m = sandwiches.length;
        Deque<Integer> st = new ArrayDeque<>();
        Deque<Integer> ss = new ArrayDeque<>();
        for(int i=0;i<n;i++){
            st.addFirst(students[i]);
            cost += students[i];
            czst += 1-students[i];    
        }
        for(int i=0;i<m;i++){
            ss.addFirst(sandwiches[m-i-1]);
            cosa += sandwiches[m-i-1];
            czsa += 1-sandwiches[m-i-1];
        }
        int cc =0;
        while(!st.isEmpty() && !ss.isEmpty()){
            int a = st.pollFirst();
            int b = ss.pollFirst();
            if( a != b ){
                st.addLast(a);
                ss.addFirst(b);
                cc ++;
                if( cc > 3*n ){
                    break;
                }
            }
            else{
                cost-=a;
                cosa-=a;
                czst-=1-a;
                czsa-=1-a;
            }
        }
        return st.size();
    }
}