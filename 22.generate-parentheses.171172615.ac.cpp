class Solution {
public:
    vector<string> ans;
    void recfunc(deque<char> mydeq, int left, int right) {
	if(left == 0 && right == 0){
	    string s;
	    for(deque<char>::iterator it = mydeq.begin(); it != mydeq.end(); ++it) {
		s += *it;
	    }
	    ans.push_back(s);
	}else if(left == right) {
	    mydeq.push_back('(');
	    recfunc(mydeq, left - 1, right);
	}else{
	    deque<char> tmp = mydeq;
	    if(left > 0) {
		mydeq.push_back('(');
		recfunc(mydeq, left - 1, right);
	    }
	    tmp.push_back(')');
	    recfunc(tmp, left, right - 1);
	}
    }

    vector<string> generateParenthesis(int n) {
	deque<char> mydeq;
	recfunc(mydeq, n, n);
	return ans;
    }
};
