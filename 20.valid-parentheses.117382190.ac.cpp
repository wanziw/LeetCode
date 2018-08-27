class Solution {
public:
    bool isValid(string s) {
	stack<char> mystk;
	for(int i = 0; i < s.length(); i++) {
	    if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
		mystk.push(s[i]);
	    }else if(s[i] == ')') {
		if(mystk.empty()) return false;
		if(mystk.top() == '(')
		    mystk.pop();
		else
		    return false;
	    }else if(s[i] == ']') {
		if(mystk.empty()) return false;
		if(mystk.top() == '[')
		    mystk.pop();
		else
		    return false;
	    }else if(s[i] == '}') {
		if(mystk.empty()) return false;
		if(mystk.top() == '{')
		    mystk.pop();
		else
		    return false;
	    }
	}
	if(!mystk.empty())
	    return false;

	return true;
        
    }
};

