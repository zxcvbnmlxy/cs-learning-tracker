class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s;
        for (auto x : chunks)s += x;
        unordered_map<string, int>word_count;
        int n = s.size();
        int i = 0;
        while (i < n) {
            while (i < n && !islower(s[i])) {
                i++;
            }
            if (i >= n)break;
            int start = i;
            while (i < n) {
                char c = s[i];
                if (islower(c)) {
                    i++;
                }
                else if (c == '-') {
                    if (i > start && i + 1 < n && islower(s[i - 1]) && islower(s[i + 1])) {
                        i++;
                    }
                    else break;
                }
                else break;
            }
            string word = s.substr(start, i - start);
            if (!word.empty() && word.front() != '-' && word.back() != '-') {
                word_count[word]++;
            }
        }
        vector<int>ans;
        for (auto q : queries) {
            ans.push_back(word_count.count(q) ? word_count[q] : 0);
        }
        return ans;
    }
};