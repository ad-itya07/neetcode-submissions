class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for (auto str: strs) {
            for (char c: str) {
                s += char(c + 5);
            }

            s+= '"';
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        
        int i = 0;
        while (i < s.size()) {
            string temp = "";
            while (i < s.size() && s[i] != '"') {
                temp += char(s[i] - 5);
                i++;
            }

            ans.push_back(temp);
            i++;
        }

        return ans;
    }
};
