class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& candidates, vector<int>& tmp, int target, int state, int sum) {
	if(sum == target) {
	    ans.push_back(tmp);
	    return ;
	}
	if(sum > target) return ;

	for(int i = state; i < candidates.size(); i++) {
	    tmp.push_back(candidates[i]);
	    sum += candidates[i];
	    dfs(candidates, tmp, target, i, sum);

	    tmp.pop_back();
	    sum -= candidates[i];
	}

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<int> tmp;
	dfs(candidates, tmp, target, 0, 0);
	return ans;
    }
};
