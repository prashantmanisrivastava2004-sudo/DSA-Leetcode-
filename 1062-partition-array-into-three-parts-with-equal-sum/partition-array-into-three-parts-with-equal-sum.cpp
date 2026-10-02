class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int arraysum = 0;
        for(int x: arr){
            arraysum += x;
        }
        if(arraysum % 3 != 0){
            return false;
        }
        int target = arraysum/3;
        int sum =0;
        int part =0;

        for(int x: arr){
            sum += x;

            if(sum == target){
                part++;
                sum=0;
            }
        }
        if(part >= 3){
            return true;
        }
        return false;

    }
};