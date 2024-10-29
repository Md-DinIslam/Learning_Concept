#define ff first
#define ss second
#define pb push_back
#define pp pop_back
#define arr array
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()

class Solution {
    map<string, int> cnt;
    vector<vector<string>> ans;
    string begin_str;
private:
    void dfs(string end_str, vector<string> &seq) {
        if (end_str == begin_str) {
            reverse(all(seq));
            ans.pb(seq);
            reverse(all(seq));
            return;
        }

        int steps = cnt[end_str];
        for (auto &ch : end_str) {
            char orginal = ch;
            for (int i = 0; i < 26; ++i) {
                ch = i + 'a';
                if (cnt.count(end_str)) {
                    if (cnt[end_str] == steps - 1) {
                        seq.pb(end_str);
                        dfs(end_str, seq);
                        seq.pp();
                    }
                }
            }
            ch = orginal;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(all(wordList));
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);
        cnt[beginWord] = 1;
        begin_str = beginWord;

        while (q.size()) {
            string str = q.front().ff;
            int steps = q.front().ss;
            q.pop();
            cnt[str] = steps;

            if (str == endWord) {
                break;
            }

            for (auto &ch : str) {
                char orginal = ch;
                for (int i = 0; i < 26; ++i) {
                    ch = i + 'a';
                    auto it = st.find(str);
                    if (it != st.end()) {
                        q.push({str, steps + 1});
                        st.erase(it);
                        // cnt[str] = steps + 1;
                    }
                }
                ch = orginal;
            }
        }

        if (cnt.find(endWord) != cnt.end()) {
            vector<string> seq(1, endWord);
            dfs(endWord, seq);
        }

        return ans;
    }
};