class Solution {
public:
    int minAbsoluteDifference(vector<int>& a) {
        int l1=-1,l2=-1,ans=INT_MAX;
        for(int i=0;i<a.size();i++){
            if(a[i]==1){
                l1=i;
                if(l2!=-1){
                    ans=min(ans,abs(l1-l2));
                }
            }
            else if(a[i]==2){
                l2=i;
                if(l1!=-1){
                    ans=min(ans,abs(l1-l2));
                }
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};