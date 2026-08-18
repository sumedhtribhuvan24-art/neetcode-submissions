class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for(auto& entry :mp){
        int num = entry.first;
        int freq = entry.second;

        bucket[freq].push_back(num);
        }

        vector<int> result;
        for(int freq = bucket.size()-1; freq>=1 && result.size()<k; freq--){
            for(int num : bucket[freq]){
                result.push_back(num);
                if(result.size()==k)break;
            }
        }
        return result;
    }
};
