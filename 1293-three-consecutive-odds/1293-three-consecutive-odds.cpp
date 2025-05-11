//(Iterating checking count of odd elements)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int oddCount = 0;

        for(int i = 0; i < n; i++) {
            if(arr[i] % 2 == 1) {
                oddCount++;
            } else {
                oddCount = 0;
            }

            if(oddCount == 3)
                return true;
        }
        return false;
    }
};