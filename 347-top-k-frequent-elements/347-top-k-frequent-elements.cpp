class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> v;
        std::unordered_map<int, int> count_map;
        
        for ( auto n : nums ){
            count_map[n]++;
        } 
        
        std::priority_queue<std::pair<int, int>> maxHeap;
        
        for ( auto& pair : count_map ) { 
            maxHeap.emplace(pair.second, pair.first);
        }
        
        while ( k-- ) {
            v.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return v;
    }
};