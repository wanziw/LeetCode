class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<vector<int>>& count, vector<int>& tmp, int target, int state, int sum) {
	if(sum == target) {
	    ans.push_back(tmp);
	    return ;
	}
	if(sum > target) return ;
	
	for(int i = state; i < count.size(); i++) {
	    if(count[i][1] == 0) continue;
	    else {
		tmp.push_back(count[i][0]);
		sum += count[i][0];
		count[i][1]--;
		dfs(count, tmp, target, i, sum);

		tmp.pop_back();
		sum -= count[i][0];
		count[i][1]++;
	    }
	}
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> count;

	if(candidates.size() == 0) return count;

	int c = 0;
	int num = candidates[0];
	vector<int> t(2);
	for(int i = 0; i < candidates.size(); i++) {
	    if(candidates[i] != num) {
		t[0] = num;
		t[1] = c;
		count.push_back(t);
		c = 1;
		num = candidates[i];
	    }else{
		c++;
	    }
	}
	t[0] = num;
	t[1] = c;
	count.push_back(t);
	vector<int> tmp;
	dfs(count, tmp, target, 0, 0);

	return ans;
    }
};
