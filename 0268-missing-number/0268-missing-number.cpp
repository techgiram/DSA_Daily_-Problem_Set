class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int pahije_to_num = n*(n+1)/2;

        int khara_num = 0;

        // purn array la traverse karun tyachya pratyek index cha sum ghenya sathi ha for loop

        for(int i=0; i<n; i++){
            // hi line sum sathi ahe
            khara_num += nums[i];
        }
        // hi line pahije to ani kharya num chi vajabaki karun missing value denya sathi
        return pahije_to_num - khara_num;
    }
};