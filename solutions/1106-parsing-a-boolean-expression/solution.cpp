class Solution {
public:
    bool parseBoolExpr(string expression) {
        int index = 0;
        return evaluate(expression, index);
    }
private:
    bool evaluate(string& expr, int& index) {
        char currChar = expr[index++];
        if (currChar == 't') return true;
        if (currChar == 'f') return false;
        if (currChar == '!') {
            index++;  // Skip '('
            bool result = !evaluate(expr, index);
            index++;  // Skip ')'
            return result;
        }
        vector<bool> values;
        index++;  // Skip '('
        while (expr[index] != ')') {
            if (expr[index] != ',') {
                values.push_back(evaluate(
                    expr, index));
            } else {
                index++;
            }
        }
        index++;
        if (currChar == '&') {
            for (bool v : values) {
                if (!v) return false;
            }
            return true;
        }
        if (currChar == '|') {
            for (bool v : values) {
                if (v) return true;
            }
            return false;
        }

        return false; 
    }
};