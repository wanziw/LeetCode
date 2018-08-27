class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
	int mini = -2147483648;

	for(int i = 0; i < nums.size(); i++) {
	    if(mini < nums[i]) {
		mini = nums[i];
	    }else if(mini == nums[i]){
		nums.erase(nums.begin() + i);
		i--;
	    }
	}

	return nums.size();
    }
};

