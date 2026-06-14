class Solution {
public:
    string khan(int n, unordered_map<char, vector<char>>& edges) {
        unordered_map<char, int> indegree;

        for (auto it: edges) {
            if (indegree.find(it.first) == indegree.end()) indegree[it.first] = 0;
            for (auto adjNode: it.second) {
                indegree[adjNode]++;
            }
        }

        queue<char> q;

        for (auto it: indegree) if (it.second == 0) q.push(it.first);

        string ans = "";
        while (!q.empty()) {
            char letter  = q.front();
            q.pop();

            ans+=letter;

            for (auto adjLetter: edges[letter]) {
                indegree[adjLetter]--;

                if (indegree[adjLetter] == 0) q.push(adjLetter);
            }
        }

        return ans;
    }
    string foreignDictionary(vector<string>& words) {
        int n = words.size();

        if (n==1) return words[0];

        unordered_set<char> st;

        for (int i=0; i<n; i++) {
            int t1 = 0;
            while (t1 < words[i].size()) {
                st.insert(words[i][t1]);
                t1++;
            }
        }

        unordered_map<char, vector<char>> edges;
        for (auto it: st) {
            edges[it] = {};
        }

        for (int i=0; i<n-1; i++) {
            string s1 = words[i];
            string s2 = words[i+1];

            int t1 = 0; int t2=0;

            bool misMatch = false;
            while (t1 < s1.size() && t2 < s2.size()) {
                if (s1[t1] != s2[t2]) {
                    misMatch = true;
                    edges[s1[t1]].push_back(s2[t2]);
                    break;
                }
                t1++; t2++;
            }

            if (!misMatch && s1.size() > s2.size()) return "";
        }

        string ans = khan(st.size(), edges);

        return ans.size() == st.size() ? ans : "";
    }
};
