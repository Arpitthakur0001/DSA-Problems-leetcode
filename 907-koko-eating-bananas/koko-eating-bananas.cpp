class Solution {
public:

    bool possible(vector<int>& piles, int h, int k)
    {
        long long totalHours = 0;

        for(int i = 0; i < piles.size(); i++)
        {
            // Hours needed for current pile
            totalHours += (piles[i] + k - 1) / k;
        }

        return totalHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h)
    {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = high;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(possible(piles, h, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};