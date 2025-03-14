class Solution {
    public:
        int candy(vector<int>& ratings) {
            int n = ratings.size();
            
            //give each child one candy at first time
            vector<int> candies(n, 1);
            
            bool stop = false;
            while(!stop){
                stop = true;
                for(int i = 0; i < n; ++i){
                    if(i > 0 && ratings[i] > ratings[i-1]){
                        if(candies[i] <= candies[i-1]){
                            stop = false;
                            candies[i] = candies[i-1]+1;
                        }
                    }
                    if(i < n-1 && ratings[i] > ratings[i+1]){
                        if(candies[i] <= candies[i+1]){
                            stop = false;
                            candies[i] = candies[i+1]+1;
                        }
                    }
                }   
            }
            
            return accumulate(candies.begin(), candies.end(), 0);
        }
    };