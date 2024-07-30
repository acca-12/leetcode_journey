class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(string &c: tokens){
            if(c.compare("+") == 0){
                string x = s.top();
                s.pop();
                string y = s.top();
                s.pop();
                int result = stoi(x) + stoi(y);
                s.push(to_string(result));
            }else if(c.compare("-") == 0){
                string x = s.top();
                s.pop();
                string y = s.top();
                s.pop();
                int result = stoi(y) - stoi(x);
                s.push(to_string(result));

            }else if(c.compare("*") == 0){
                string x = s.top();
                s.pop();
                string y = s.top();
                s.pop();
                int result = stoi(x) * stoi(y);
                s.push(to_string(result));

            }else if (c.compare("/") == 0){
                string x = s.top();
                s.pop();
                string y = s.top();
                s.pop();
                int result = stoi(y) / stoi(x);
                s.push(to_string(result));
            }else{
                s.push(c);
            }
        }
        return stoi(s.top());
    }
};
