class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        int n = words.size();
        for(int i = 0; i<n; i++){
            if(find(words[i].begin(), words[i].end(), x) != words[i].end()){
                result.push_back(i);
            }
        }
        return result;
        
    }
};