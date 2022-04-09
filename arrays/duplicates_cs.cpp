int findDuplicate(vector<int> &arr) 
{
    // Write your code here
	int answer=0;
	for(int i=0;i<arr.size();i++){
		answer=answer^arr[i];
	}
	for(int i=1;i<arr.size();i++){
		answer=answer^i;
	}
	return answer;
}
