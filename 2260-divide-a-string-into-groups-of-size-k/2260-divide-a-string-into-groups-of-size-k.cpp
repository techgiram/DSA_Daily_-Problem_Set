class Solution {
public:
   vector<string> divideString(string s, int k, char fill) {
    vector<string> result;
    for (int i = 0; i < s.length(); i += k) {
        string group = s.substr(i, k);
        if (group.length() < k) {
            group += string(k - group.length(), fill); // Add fill characters
        }
        result.push_back(group);
    }
    return result;
}
};