class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>st;
        stack<int>sd;
        for(int i=0;i<students.size();i++){
            st.push(students[i]);
        }
         for(int i=sandwiches.size()-1;i>=0;i--){
            sd.push(sandwiches[i]);
        }
        int rotation =0;
        while(!st.empty() && rotation<st.size()){
            if(sd.top()==st.front()){
                sd.pop();
                st.pop();
                rotation=0;
            }
            else{
                int val=st.front();
                st.pop();
                st.push(val);
                rotation++;
            }
        }
        return st.size();
    }
};