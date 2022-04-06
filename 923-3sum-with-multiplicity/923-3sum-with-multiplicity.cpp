class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) 
    {
        long long ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        { int t=target-arr[i];
            for (int j=i+1;j<arr.size();j++)
            {
                if(mp.find(t-arr[j])!=mp.end())
                { 
                    ans+=mp[t-arr[j]];
                }
            }
         mp[arr[i]]++;
                
        }
        
        return ans%1000000007;
    }
    
};