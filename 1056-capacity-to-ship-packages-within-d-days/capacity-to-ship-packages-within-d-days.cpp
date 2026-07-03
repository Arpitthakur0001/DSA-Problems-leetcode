class Solution {
public:

    bool possible(vector<int>& weights, int days, int capacity)
    {
        int currentLoad = 0;
        int requiredDays = 1;

        for(int i = 0; i < weights.size(); i++)
        {
            // Agar current package add karne se capacity exceed ho rahi hai
            if(currentLoad + weights[i] > capacity)
            {
                requiredDays++;          // Naya din start
                currentLoad = weights[i]; // Current package naye din mein load hoga
            }
            else
            {
                currentLoad += weights[i];
            }
        }

        return requiredDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days)
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;

        for(int weight : weights)
        {
            high += weight;
        }

        int ans = high;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(possible(weights, days, mid))
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