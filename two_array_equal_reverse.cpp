class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> yes;

        for(int i = 0; i < target.size(); i++){
            yes[target[i]]++;
            yes[arr[i]] --;
        }

        for (const auto& pair : yes) {
            if (pair.second != 0) {
                return false;
            }
        }
        return true;
    }
};
