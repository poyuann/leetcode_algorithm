class Solution {
    public:
        int paintWalls(vector<int>& cost, vector<int>& time) {
            int n = cost.size();
            for(int i = 0; i < n; i++) {
                // if the paid painter paints the `i`th wall, we can paint `times[i] + 1` walls,
                // 1 wall by the paid painter, and `times[i]` walls by the free painter,
                // we can simplify this if we supose that we can paint `times[i] + 1` walls if the paid painter select this wall
                time[i]++;
            }
    
            // the vector where we will have the answers
            // `answers[i]` will have the optimal cost of painting `i` walls
            vector<int> answers = vector<int>(n + 1, 1e9);
            // painting 0 walls will cost 0
            answers[0] = 0;
            // at the end we'll return `answers[n]`; the cost of painting `n` walls
    
            // now we iterate over the walls
            for(int idx = 0; idx < n; idx++) {
                int wallCost = cost[idx];
                int wallTime = time[idx];
                // now we'll check if we can improve `answers[i]` for each `i`
                // the index starts at `n`, so we avoid the case of using a wall multiple times
                for(int i = n; i >= 1; i--) {
                    // we do `max(0, other)` so we don't go below index `0`
                    int remainingWalls = max(0, i - wallTime);
                    if(answers[remainingWalls] + wallCost < answers[i]) {
                        // if we find an improvement we update the cost
                        answers[i] = answers[remainingWalls] + wallCost;
                    }
                }
            }
    
            // the final answer is the cost of painting all the walls, this is `answers[n]`
            return answers[n];
        }
    };