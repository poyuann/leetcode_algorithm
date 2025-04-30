class Solution {
    public:
        int paintWalls(vector<int>& cost, vector<int>& time) {
            int n = cost.size();
            for(int i = 0; i < n; i++) time[i]++;
    
            vector<int> answers = vector<int>(n + 1, 1e9);
            answers[0] = 0;
    
            for(int idx = 0; idx < n; idx++) {
                int wallCost = cost[idx];
                int wallTime = time[idx];
                for(int i = n; i >= 1; i--) {
                    int remainingWalls = max(0, i - wallTime);
                    if(answers[remainingWalls] + wallCost < answers[i]) {
                        answers[i] = answers[remainingWalls] + wallCost;
                    }
                }
            }
    
            return answers[n];
        }
    };