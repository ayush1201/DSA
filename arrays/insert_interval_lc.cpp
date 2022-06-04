//first while loop will be for printing intervals less than newINterval.
//second while is for taking common interval between intervals and newInterval.
//thord loop is for printing intervals bigger than newInterval.
//time complexity o(N).
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       vector<vector<int>> ans;
        int length=newInterval.size()-1;
        int i=0;
               while((i<intervals.size())&&(intervals[i][1]<newInterval[length-1])){
                   ans.push_back(intervals[i]);
                   i++;
               }
               while((i<intervals.size())&&(newInterval[length]>=intervals[i][0])){
                   newInterval[0]=min(newInterval[length-1],intervals[i][0]);
                   newInterval[1]=max(newInterval[length],intervals[i][1]);
                   
                   i++;
                   
               }
               ans.push_back(newInterval);
               while((i<intervals.size())&&(intervals[i][0]>newInterval[length])){
                   ans.push_back(intervals[i]);
                   i++;
               }
        
        return ans;
    }
};