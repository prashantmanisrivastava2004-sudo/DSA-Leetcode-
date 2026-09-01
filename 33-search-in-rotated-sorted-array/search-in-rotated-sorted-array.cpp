class Solution {
public:
    int minidx(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }
    int binary_search(vector<int>& nums, int start, int end, int target) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int min = minidx(nums);

        int left = binary_search(nums, 0, min - 1, target);

        if (left != -1) {
            return left;
        }

        return binary_search(nums, min, nums.size() - 1, target);
    }
};