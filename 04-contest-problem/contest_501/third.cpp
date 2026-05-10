class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        long long ans = 0;
        int max_val = 0;
        for (int i = 0;i < nums.size();i++) {
            max_val = max(max_val, nums[i]);
        }
        vector<int>dp(max_val + 1);//dp[i]表示值为i能替换的最小数
        for (int i = 0;i <= max_val;i++) {
            dp[i] = i;
        }
        unordered_set<int>s(nums.begin(), nums.end());
        //dp[k*nums[i]]=min(dp[k*nums[i]],dp[nums[i]]);遍历所有值为nums[i]倍数的数,替换成nums[i]
        for (auto num : s) {
            for (int cur = num;cur <= max_val;cur += num) {
                dp[cur] = min(dp[cur], dp[num]);
            }
        }
        for (auto x : nums) {
            ans += dp[x];
        }
        return ans;
    }
};