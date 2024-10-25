class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        ans=[]
        st=set()
        folder.sort()
        for i in folder:
            tmp=""
            f=True
            for j in i:
                tmp=tmp+j
                if (j=="/" and tmp[:-1] in st) or (tmp+"/" in st):
                    f=False
                    break
            st.add(i)
            if f:
                ans.append(i)
        return ans