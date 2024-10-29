#define ff first
#define ss second
#define pb push_back
#define pp pop_back
#define arr array
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()

class solution {
public:
	vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
		// code here
		set<string> st(all(wordList)); // for finding string in O(logN).....
		queue<vector<string>> q;
		q.push({beginWord});
		st.erase(beginWord); // Initially visited, so erase it....
		vector<string> vis_str_level; // mark as visited...
		int steps = 1;

		vector<vector<string>> ans;
		while (q.size()) {
			auto vec_str = q.front();
			q.pop();

			// Before going next level delete previous level visited string.....
			if (sz(vec_str) > steps) {
				steps += 1;
				for (auto &s : vis_str_level) {
					st.erase(s);
				}
				vis_str_level.clear();
			}

			// We have sequence, so only need to calculate last one and make new sequence.....
			string str = vec_str.back();
			// If we found target string.. then put it all the string of same size (because of shortest path) into the ans.....
			if (str == endWord) {
				if (sz(ans)) {
					if (sz(ans[0]) == sz(vec_str)) {
						ans.pb(vec_str);
					}
				}
				else {
					ans.pb(vec_str);
				}
			}

			for (auto &ch : str) {
				char orginal = ch;
				// Changing it all the single character & finding the closest one.....
				for (int i = 0; i < 26; ++i) {
					ch = i + 'a';
					auto it = st.find(str);
					if (it != st.end()) {
						vec_str.pb(str); // If we find, then add into the new sequence...
						q.push(vec_str);
						vis_str_level.pb(str); // mark this visited....
						vec_str.pp(); // for multiple sequence of same size we need to remove the previously added string...
					}
				}
				ch = orginal; // make sure the string is same like before all the operation....
			}
		}

		return ans;
	}
};