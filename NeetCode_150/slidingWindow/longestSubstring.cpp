class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;

        unordered_map<char,int> mpp;
        int ans=0,cnt=0;

        for(int i = 0; i < s.size(); i++){

            if(mpp.find(s[i])==mpp.end()){
                cnt++;
                mpp[s[i]]++;
            }

            else{
                mpp.erase(s[i]);
                cnt-=1;
                mpp[s[i]]++;
                cnt++;
                ans=max(cnt,ans);
            }
        }

        ans=max(cnt,ans);
        return ans;
        
    }
};
