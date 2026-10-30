class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int Cnt = 0;
        int maxCnt = 0;
        for (int x: nums) {
            if (x==0) 
                Cnt = 0;
            else {
                Cnt++;
                maxCnt = max(Cnt, maxCnt);
            }
        }
        return maxCnt;
    }
};