class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int Q = queries.size();

        priority_queue<int> max_heap; 
        priority_queue<int , vector<int>, greater<int>> past;

        sort(begin(queries), end(queries));

        int j=0;
        int usedCount = 0;

        for(int i= 0; i<n; i++){
            while(j < Q && queries[j][0] == i){
                max_heap.push(queries[j][1]);
                j++;
            }

            nums[i] -= past.size();

            while(nums[i] > 0 && !max_heap.empty() && max_heap.top() >= i){
                int ending = max_heap.top();
                max_heap.pop();
                past.push(ending);
                usedCount++;
                nums[i]--;
            }

            if(nums[i] > 0){
                return -1;
            }

            while(!past.empty() && past.top() <= i){
                past.pop();
            }
        }
        
        return Q - usedCount;
    }
};