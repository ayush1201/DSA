public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char,int> mp;  
		    queue<char> q;
		    string ans="";
		    //step1: count the occurences of chars of given string.
		    for(int i=0;i<A.length();i++){
		        char ch = A[i];
		        mp[ch]++;
		        q.push(ch);
		    
		    
		    //step2: now simply empty the queue with repeating chars and for non repeating just store that from queue front.
		    while(!q.empty()){
		        if(mp[q.front()]>1){
		            //repeating
		            q.pop();
		        }
		        else{
		            //non repeating first char.
		            ans.push_back(q.front());
		            break;
		        }
		    }
		    //if queue becomes empty and no non repeating char is found.
		    if(q.empty()){
		        ans.push_back('#');
		     }
		    }
		    return ans;
		}