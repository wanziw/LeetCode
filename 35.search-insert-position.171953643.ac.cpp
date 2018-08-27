class Solution {
public:
    int searchFunc(vector<int>& nums, int start, int end, int target) {
	if(start > end) return start;

	int mid = (start + end) / 2;

	if(nums[mid] == target) return mid;

	if(target <= nums[mid]) {
	    return searchFunc(nums, start, mid - 1, target);
	}
	if(target >= nums[mid]){
	    return searchFunc(nums, mid + 1, end, target);
	}
    }

    int searchInsert(vector<int>& nums, int target) {
	return searchFunc(nums, 0, nums.size() - 1, target);
    }
};
