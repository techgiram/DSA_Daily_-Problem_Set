class Solution {
public:
    vector<string> columnStates;
    int M = 1e9+7;
    vector<vector<int>> t;
     void generateColumStates(string curr, char prevChar, int l, int m){
        if(l == m){
            columnStates.push_back(curr);
            return;
        }

        for(char ch : {'R', 'G','B'}){
            if(ch == prevChar)
                continue;
            
            generateColumStates(curr + ch, ch, l+1, m);
        }
    }

    int solve(int remainCols, int prevIdx, int m){
        if(remainCols == 0){
            return 1;
        }

        if(t[remainCols] [prevIdx] != -1){
            return t[remainCols] [prevIdx];
        }
        int ways = 0; 
        string prevStates = columnStates[prevIdx];

        for(int i= 0; i<columnStates.size(); i++){
            if(i == prevIdx) continue;

            string currStates = columnStates[i];
            bool valid = true;

            for(int j=0; j<m; j++){
                if(prevStates[j] == currStates[j]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                ways = (ways + solve(remainCols-1,i, m)) % M;
            }
        }
        return t[remainCols] [prevIdx] = ways;
    }
    int colorTheGrid(int m, int n) {
        //step-1 generate colom state
        generateColumStates("", '#',0,  m);
        int totalStates = columnStates.size();

        t = vector<vector<int>>(n+1, vector<int>(totalStates+1, -1));

        int result = 0;
        for(int i= 0; i<columnStates.size(); i++){
            result = (result + solve(n-1, i,m)) % M;
        }
        return result;
    }
};