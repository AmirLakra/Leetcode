class Solution {
public:
    const int M = 1e9+7;
    int find_power(long long a , long long b){
        if(b == 0){
            return 1;
        }
        long long half = find_power(a,b/2);
        long long result = (half * half)% M;
        if(b%2 == 1){
            result = (result * a)% M;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        return (long long)find_power(5,(n+1)/2) * find_power(4,n/2) % M;
    }
};