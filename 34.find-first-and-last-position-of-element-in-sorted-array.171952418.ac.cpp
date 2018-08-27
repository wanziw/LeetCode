class Solution {
public:
    void compare(vector<int>& a, vector<int>& b) {
	a[0] = min(a[0], b[0]);
	a[1] = max(a[1], b[1]);
    }

    vector<int> searchFunc(vector<int>& nums, vector<int> ans, int target, int start, int end) {
	if(start > end) return ans;

	int mid = (start + end) / 2;

	if(nums[mid] == target) {
	    ans[0] = mid;
	    ans[1] = mid;
	}

	vector<int> tmp(2, -1);
	if(target <= nums[mid]) {
	    tmp = searchFunc(nums, ans, target, start, mid - 1);
	    compare(ans, tmp);
	}
	if(target >= nums[mid]){
	    tmp = searchFunc(nums, ans, target, mid + 1, end);
	    compare(ans, tmp);
	}

	return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> ans {nums.size(), -1};
	ans = searchFunc(nums, ans, target, 0, nums.size() - 1);
	if(ans[0] == nums.size() || ans[1] == -1)
	    ans[0] = ans[1] = -1;

	return ans;
    }
};
