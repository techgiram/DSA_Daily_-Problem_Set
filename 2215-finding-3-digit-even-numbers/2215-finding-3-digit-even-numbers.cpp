class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();

        for(int i=0; i<n; i++){
            for(int j= 0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(i==j || j==k || i==k){
                        continue;
                    }
                    int num = nums[i] * 100 + nums[j] * 10 + nums[k];

                    if(num >= 100 && num % 2 == 0){
                        st.insert(num);
                    }
                }
            }
        }

        vector<int> result(begin(st), end(st));
        sort(begin(result), end(result));
        return result;

    }
};