class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> valueToIndices; //value: indices+1
        int size = nums.size();
        vector<int> result;
        
        for(int i = 0; i < size; ++i) {
            if(valueToIndices[target-nums[i]]) {
                result.push_back(valueToIndices[target-nums[i]] - 1);
                result.push_back(i);
                break;
            }
            else {
                valueToIndices[nums[i]] = i + 1;
            }
        }
        
        return result;
    }
};