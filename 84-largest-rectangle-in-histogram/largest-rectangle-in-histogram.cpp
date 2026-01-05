class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> st;
        int maxarea = 0;
        for(int i = 0; i < heights.size() ; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int height = heights[st.top()];
                st.pop();

                int width;
                if(st.empty()) width = i;
                else
                    width = i - st.top() - 1;

                    maxarea = max(maxarea , height*width);
            }
             st.push(i);
        }
        return maxarea;
        
    }
};