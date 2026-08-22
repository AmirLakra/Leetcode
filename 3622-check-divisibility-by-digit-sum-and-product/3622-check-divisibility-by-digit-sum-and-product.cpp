class Solution {
public:
    int total(int n){
        long long sum = 0 , mul = 1;
        while(n){
            int temp = n%10;
            sum = sum + temp;
            mul = mul * temp;
            n = n/10;
        }
        return sum+mul;
    }

    bool checkDivisibility(int n) {
        int divisor = total(n);
        if(n%divisor == 0){
            return true;
        }
        return false;
    }
};