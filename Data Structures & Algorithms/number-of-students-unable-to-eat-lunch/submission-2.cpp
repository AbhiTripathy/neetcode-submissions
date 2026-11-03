class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int stFront = 0, i = 0;
        while (i < sandwiches.size()) {
            if (students[stFront] == sandwiches[i]) {
                stFront++;
                i++;
            }
            int cnt = 0;
            while (cnt < (students.size() - stFront) && students[stFront] != sandwiches[i]) {
                students.push_back(students[stFront++]);
                cnt++;
            }
            if (cnt == students.size() - stFront) return cnt;
        }
        return 0;
    }
};