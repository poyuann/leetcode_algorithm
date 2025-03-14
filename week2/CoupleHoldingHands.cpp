class Solution {
    public:
        int minSwapsCouples(vector<int>& row) {
            int result = 0;
            for (int i = 0; i < row.size(); i+=2)
            {
                if (row[i]/2 != row[i+1]/2) 
                {
                    for (int j = i+2; j < row.size(); j+=2)
                    {
                        int s = -1;
                        if (row[i]/2 == row[j]/2)
                        {
                            s = j;
                        }
                        else if (row[i]/2 == row[j+1]/2)
                        {
                            s = j+1;
                        }
                        if (s != -1)
                        {
                            int temp = row[i+1];
                            row[i+1] = row[s];
                            row[s] = temp;
                            result++;
                            break;
                        }
                    }
                }
            }
            return result;
        }
    };
    