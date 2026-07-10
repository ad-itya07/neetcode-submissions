class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (auto str: strs) {
            for (auto c: str) {
                res += char(c+5);
            }
            res += '"';
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        
        int i=0;
        while (i<s.size()) {
            string word = "";
            while (s[i] != '"') {
                word += char(s[i] - 5);
                i++;
            }

            ans.push_back(word);
            i++;
        }

        return ans;
    }
};
