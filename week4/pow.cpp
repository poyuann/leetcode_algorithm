class Solution {
    public:
        double myPow(double x, int n) {
            double re=0;
            if(n==0) return 1;
            if(n==1) return x;
            if(n==-1) return 1.0/x;
            re = myPow(x,n/2);
            if(n%2==1) return re*re*x;
            else if(n%2== 0) return re*re;
            else return re*re/x;
        }
    };