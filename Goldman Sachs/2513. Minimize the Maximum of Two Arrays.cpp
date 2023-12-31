class Solution {
public:
    int minimizeSet(int d1, int d2, int uc1, int uc2) {
        long l=2,r=1e10;
        while(l<r){
            long m=l+(r-l)/2;
            if(check(d1,d2,uc1,uc2,m)) r=m;
            else l=m+1;
        }
        return l;
    }
    bool check(long d1,long d2,long uc1,long uc2,long m){
        long a=m-(m/d1); // Count of no not divisible by d1
        long b=m-(m/d2); // Count of no not divisible by d2
        long c=m-(m/d1)-(m/d2)+(m/lcm(d1,d2)); // Count of no not divisible by d1 as well as d2
        return (a>=uc1 && b>=uc2 && uc1+uc2<=a+b-c);
    }
};
// m=total
// Count of no div by d1, a=m/d1
// Count of no div by d2, b=m/d2
// Count of no not div by d1, a'=m-m/d1
// Count of no div by d2, b'=m-m/d1
// eg: m=15,d1=5,d2=3 => 15/3=5:(3,6,9,12,15) & 15/5=3:(5,10,15)
// Count of no divisible by both d1 as well as d2,c=m/lcm(d1,d2)
// Count of no not divisible by d1 as well as d2=m-a-b+c
