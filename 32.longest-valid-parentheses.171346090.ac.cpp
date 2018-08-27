class Solution {
public:
    int longestValidParentheses(string s) {
	if(s.length() < 2)
	    return 0;
	int ans = 0, count = 0, len = s.length();
	int mark[len];
	stack<int> num;

	memset(mark, 0, sizeof(mark));

	for(int i = 0; i < len; i++) {
	    if(s[i] == '(') {
		num.push(i);
	    }else if(s[i] == ')') {
		if(!num.empty() && s[num.top()] == '(') {
		    mark[num.top()] = 1;
		    mark[i] = 1;
		    num.pop();
		}else{
		    num.push(i);
		}
	    }
	}
	for(int i = 0; i < len; i++) {
	    if(mark[i]) 
		count++;
	    else {
		ans = max(ans, count);
            count = 0;
	    }
	}
	ans = max(ans, count);
	return ans;
    }
};
