class Solution {
public:
    int strStr(string haystack, string needle) {
	int *failure = new int[needle.size()];

	if(needle.size() == 0)
	    return 0;
	if(haystack.size() == 0)
	    return -1;
	
	for(int i = 1, j = failure[0] = -1; i < needle.size(); i++) {
	    while(j >= 0 && needle[j + 1] != needle[i])
		j = failure[j];
	    if(needle[j + 1] == needle[i])
		j++;
	    failure[i] = j;
	}

	for(int i = 0, j = -1; i < haystack.size(); i++) {
	    while(j >= 0 && needle[j + 1] != haystack[i])
		j = failure[j];
	    if(needle[j + 1] == haystack[i])
		j++;
	    
	    if(j == needle.size() - 1)
		return i - needle.size() + 1;
	}
        
	return -1;
    }
};

