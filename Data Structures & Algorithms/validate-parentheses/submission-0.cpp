class Solution {
public:
    bool isValid(string s) {
        vector<char> openBrackets;
        unordered_map<char, char> br = {{'(', 1}, {'[', 2}, {'{', 3}, {')', -1}, {']', -2}, {'}', -3}};
        for (char x: s) {
            if (x == '(' || x == '[' || x == '{') {
                openBrackets.push_back(x);
            } else {
                if (openBrackets.size() == 0) return false;
                else if (br[x] + br[openBrackets.back()] == 0) {
                    openBrackets.pop_back();
                } else {
                    return false;
                }
            }
        }
        if (openBrackets.size() != 0) return false;
        return true;
    }
};
