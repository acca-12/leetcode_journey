class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        unordered_map<char, char> y = { {'(', ')'}, {'{', '}'}, {'[', ']'} };
        
        for(char &c: s){
            if(y.find(c) != y.end()){
                p.push(c);
            } else {
                if(p.empty() || y[p.top()] != c) {
                    return false;
                }
                p.pop();
            }
        }
        return p.empty();
    }
};
