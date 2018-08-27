class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer(2);
        int numbers = nums.size();
        for(int i = 0; i < numbers - 1; i++) {
            for(int j = i + 1; j < numbers; j++) {
                if(nums[i] + nums[j] == target) {
                    answer[0] = i;
                    answer[1] = j;
                    return answer;
                }
            }
        }
    }
};

