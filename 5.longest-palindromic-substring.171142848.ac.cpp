class Solution {
public:
    string longestPalindrome(string s) {
	if(s.length() <= 1)
	    return s;

	int iid, max = -1;
	int id = 0, mx = 0;
	int len = 2 * s.length() + 1;
	int z[len] = {0};
	char str[len];
	memset(str, '#', sizeof(str));
	for(int i = 0; i < s.length(); i++)
	    str[2 * i + 1] = s[i];

	z[0] = 1;
	for(int i = 1; i < len; i++) {
	    int ii = id - (i - id); 

	    if (mx > i){
		z[i] = min(z[ii], mx - i);
	    }

	    while(i - z[i] >= 0 && i + z[i] < len && str[i - z[i]] == str[i + z[i]]) {
		z[i]++;
	    }

	    if(i + z[i] > mx) {
		mx = i + z[i];
		id = i;
	    }

	    if(z[i] > max) {
		max = z[i];
		iid = i;
	    }
	}
	string ans = "";
	for (int i = iid - max + 1; i <= iid + max - 1; i++) { 
	    if (i & 1)
		ans += str[i];
	}

	return ans;
    }
};
