vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
	int i=0;int j=0;
	vector<int> inter;
	while(i<n && j<m){
		if(arr1[i]==arr2[j]){
			inter.push_back(arr1[i]);
			i++;
			j++;
		}
		else if(arr1[i]<arr2[j]){
			i++;
		}
		else{
			j++;
		}
	}
	return inter;
}