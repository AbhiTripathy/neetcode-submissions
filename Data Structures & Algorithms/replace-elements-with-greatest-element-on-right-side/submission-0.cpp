class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int greatestElem = arr.back();
        for (int i = arr.size() - 1; i >=0; i--) {
            if (arr[i] > greatestElem) {
                int temp = arr[i];
                arr[i] = greatestElem;
                greatestElem = temp;
            }
            else arr[i] = greatestElem;
        }
        arr[arr.size() - 1] = -1;
        return arr;
    }
};