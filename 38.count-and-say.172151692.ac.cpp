class Solution {
public:
    string countAndSay(int n) {
	if(n == 0) return "1";
	else if(n == 1) return "1";
	else if(n == 2) return "11";
	else if(n == 3) return "21";
	else if(n == 4) return "1211";
	else if(n == 5) return "111221";
	else if(n == 6) return "312211";
	else if(n == 7) return "13112221";
	else if(n == 8) return "1113213211";
	else if(n == 9) return "31131211131221";

	string ans = "31131211131221";

	for(int i = 10; i <= n; i++) {
	    int count = 0;
	    char currchar = ans[0];
	    string tmp = "";
	    for(int j = 0; j < ans.size(); j++) {
		if(currchar != ans[j]) {
		    tmp = tmp + to_string(count) + currchar;
		    currchar = ans[j];
		    count = 1;
		}else{
		    count++;
		}
	    }
	    ans = tmp + to_string(count) + currchar;
	}
        
	return ans;
    }
};
