class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> hours;
        for(int i = 0; i < position.size(); i++){
            hours.push_back({position[i], (double)(target - position[i]) / speed[i]});
        }
        sort(hours.begin(), hours.end());

        stack<double> f;


        //[0, 3 , 5, 8, 10]
        //[12, 3, 7, 1, 1]
        for(int i = position.size() - 1; i >= 0; i--){
            if(f.empty() || hours[i].second > f.top()){
                f.push(hours[i].second);
            }
        }
        return f.size();
    }
};
