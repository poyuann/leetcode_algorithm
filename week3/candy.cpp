class Solution {
    public:
        int candy(vector<int>& ratings) {
            vector<int> candy_list(ratings.size(), 1);
     
            for (int i = 0; i < ratings.size() - 1; i++)
            {
                if (ratings[i] < ratings[i + 1])
                {
                    candy_list[i + 1] = candy_list[i] + 1;
                }
            }
     
            for (int i = ratings.size() - 1; i >= 1; i--)
            {
                if (ratings[i - 1] > ratings[i] && candy_list[i-1] <= candy_list[i])  
                {
                    candy_list[i - 1] = candy_list[i] + 1;
                }
            }
            return accumulate(candy_list.begin(), candy_list.end(), 0);
        }
    };