class Solution {
public:
    vector<vector<char> > alphabet{{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

    vector<string> letterCombinations(string digits) {
	vector<string> answer;
	
	func(digits, 0, "", answer);

	return answer;
    }

    void func(string strs, int pos, string ans, vector<string>& answer) {
	if(ans.length() == strs.size()) {
        if(ans.length() != 0)
	        answer.push_back(ans);
	    return ;
	}
	for(int i = 0; i < alphabet[strs[pos] - 48].size(); i++) {
	    ans += alphabet[strs[pos] - 48][i];
	    func(strs, pos+1, ans, answer);
	    ans.pop_back();
	}

    }
};
