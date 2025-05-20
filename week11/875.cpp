class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min=1;
        int max=*max_element(piles.begin(), piles.end());
        while (min<=max){
            int mid=min+(max-min)/2;
            long long int totalHours=0;
            for (auto val: piles){
                int carry= (val%mid==0)? 0: 1;
                totalHours+=int(val/mid)+carry;
            }
            if (totalHours<=h)
                max=mid-1;
            else
                min=mid+1;
        }
        return min;
    }
};
