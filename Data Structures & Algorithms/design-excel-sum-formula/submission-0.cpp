class Excel {
public:
    struct Formula {
        unordered_map<string, int> cells;
        int val;
        Formula(unordered_map<string, int> c, int v) : cells(c), val(v) {}
    };

    vector<vector<Formula*>> formulas;
    stack<pair<int, int>> stk;

    Excel(int height, char width) {
        formulas.assign(height, vector<Formula*>((width - 'A') + 1, nullptr));
    }

    void set(int row, char column, int val) {
        delete formulas[row - 1][column - 'A'];
        formulas[row - 1][column - 'A'] = new Formula(unordered_map<string, int>(), val);
        topologicalSort(row - 1, column - 'A');
        execute_stack();
    }

    int get(int row, char column) {
        if (formulas[row - 1][column - 'A'] == nullptr)
            return 0;
        return formulas[row - 1][column - 'A']->val;
    }

    int sum(int row, char column, vector<string> numbers) {
        unordered_map<string, int> cells = convert(numbers);
        int summ = calculate_sum(row - 1, column - 'A', cells);
        set(row, column, summ);
        formulas[row - 1][column - 'A'] = new Formula(cells, summ);
        return summ;
    }

    void topologicalSort(int r, int c) {
        string key = string(1, 'A' + c) + to_string(r + 1);
        for (int i = 0; i < (int)formulas.size(); i++) {
            for (int j = 0; j < (int)formulas[0].size(); j++) {
                if (formulas[i][j] != nullptr && formulas[i][j]->cells.count(key)) {
                    topologicalSort(i, j);
                }
            }
        }
        stk.push({r, c});
    }

    void execute_stack() {
        while (!stk.empty()) {
            auto [r, c] = stk.top();
            stk.pop();
            if (!formulas[r][c]->cells.empty()) {
                calculate_sum(r, c, formulas[r][c]->cells);
            }
        }
    }

    unordered_map<string, int> convert(vector<string>& strs) {
        unordered_map<string, int> res;
        for (auto& st : strs) {
            if (st.find(':') == string::npos) {
                res[st]++;
            } else {
                int pos = st.find(':');
                string first = st.substr(0, pos);
                string second = st.substr(pos + 1);
                int si = stoi(first.substr(1)), ei = stoi(second.substr(1));
                char sj = first[0], ej = second[0];
                for (int i = si; i <= ei; i++) {
                    for (char j = sj; j <= ej; j++) {
                        string k = string(1, j) + to_string(i);
                        res[k]++;
                    }
                }
            }
        }
        return res;
    }

    int calculate_sum(int r, int c, unordered_map<string, int>& cells) {
        int sum = 0;
        for (auto& [s, count] : cells) {
            int x = stoi(s.substr(1)) - 1;
            int y = s[0] - 'A';
            sum += (formulas[x][y] != nullptr ? formulas[x][y]->val : 0) * count;
        }
        unordered_map<string, int> cellsCopy = cells;
        delete formulas[r][c];
        formulas[r][c] = new Formula(cellsCopy, sum);
        return sum;
    }
};
