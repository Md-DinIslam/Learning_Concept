#define ff first
#define ss second
#define all(x) x.begin(), x.end()

class DSU {
private:
    vector<int> sizes, par;
public:
    DSU(int n) {
        sizes.resize(n, 1);
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }
    int Find(int node) {
        if(node == par[node]) return node;
        return par[node] = Find(par[node]);
    }
    void Union(int x, int y) {
        int par_x = Find(x);
        int par_y = Find(y);
        if(par_x == par_y) return;
        if(sizes[par_x] < sizes[par_y]) {
            par[par_x] = par_y;
            sizes[par_y] += sizes[par_x];
        }
        else {
            par[par_y] = par_x;
            sizes[par_x] += sizes[par_y];
        }
    }
};

class Solution {    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU t(n);

        map<string, int> mailNode;
        for(int i = 0;i < n; ++i) {
            int m = accounts[i].size();
            for(int j = 1;j < m; ++j) {
                string mail = accounts[i][j];
                if(mailNode.count(mail) == 0) {
                    mailNode[mail] = i;
                }
                else {
                    t.Union(i, mailNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n];
        for(auto &pr : mailNode) {
            string mail = pr.ff;
            int node = t.Find(pr.ss);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i = 0;i < n; ++i) {
            if(mergedMail[i].size()) {
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                sort(all(mergedMail[i]));
                for(auto &x : mergedMail[i]) {
                    temp.push_back(x);
                }
                // sort(temp.begin() + 1, temp.end());
                ans.push_back(temp);
            }
        }

        return ans;
    }
};
