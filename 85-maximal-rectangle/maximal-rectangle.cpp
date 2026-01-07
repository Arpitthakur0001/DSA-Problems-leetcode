class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> st;
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

    int maximalRectangle(vector<vector<char>>& matrix) {

        if(matrix.size() == 0) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);
        int ans = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};
