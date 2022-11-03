//simple tha but nhi hua sort karo and diff aur worker wala and for every worker traverse through diff and get maxprofit at every work and then add it to the final profit and for next worker just check maxprofit till that diff task since arrays are sorted.
class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<pair<int,int>> jobs;
        for(int i=0;i<d.size();i++){
            jobs.push_back(make_pair(d[i],p[i]));
        }
        
        sort(jobs.begin(),jobs.end());
        sort(w.begin(),w.end());
        
        int maxProfit = 0;
        int profit_per_w = 0;
        int jobs_prof = 0;
        
        for(int i=0;i<w.size();i++){
            
            while(jobs_prof < d.size() && (jobs[jobs_prof].first <= w[i])){
                profit_per_w = max(profit_per_w,jobs[jobs_prof].second);
                jobs_prof++;
            }
            
            maxProfit += profit_per_w;
        }
        
        
        return maxProfit;
    }
};