int getMaxPoints(int days,int lastTask,vector<vector<int>> &points,vector<vector<int>> &dp){
    //base case when day is zero
    //ye base case me max point return karega jab last task 
    if(days == 0){
        int maxi = 0;
        for(int task=0;task<3;task++){
            if(task != lastTask){
                maxi = max(maxi,points[0][task]);
            }
        }
        return maxi;
    }
    
    if(dp[days][lastTask] != -1){
        return dp[days][lastTask];
    }
    
    int maxi = 0;
    //regular case if it is not base case.
    for(int task=0;task<3;task++){
        if(task != lastTask){
           int point = points[days][task] + getMaxPoints(days-1,task,points,dp);
           maxi = max(maxi,point);
        }
    }
    return dp[days][lastTask] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    //dp array
    vector<vector<int>> dp(n,vector<int> (4,-1));
    //return getMaxPoints(n-1,3,points,dp);
    // Write your code here.
    
    //tabulation
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    //means only one day is there and so we have three choices.
    dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]));
    
    for(int days=1;days<n;days++){
        for(int last=0;last<4;last++){
            dp[days][last] = 0;
            for(int task=0;task<3;task++){
                if(last != task){
                    int point = points[days][task] + dp[days-1][task];
                    dp[days][last] = max(point,dp[days][last]);
                }
            }
        }
    }
    return dp[n-1][3];
}