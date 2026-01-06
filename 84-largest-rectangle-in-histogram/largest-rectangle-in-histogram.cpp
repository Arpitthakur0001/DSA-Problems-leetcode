class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        heights.push_back(0); // sentinel
        stack<int> st;        // store indices
        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++) {

            while(!st.empty() && heights[st.top()] > heights[i]) {

                int idx = st.top();
                st.pop();
                int height = heights[idx];

                int width;
                if(st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};
