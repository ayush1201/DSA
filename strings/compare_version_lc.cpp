//We will use 2 pointer approach and compare each versions until '.' is found and neglecting zeroes by number1=number1*10+(version1[i]-'0') .
//Time complexity is O(n).
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1=version1.length();
        int n2=version2.length();
        int number1=0;
        int number2=0;
        int i=0;int j=0;
        while((i<n1)||(j<n2)){
            while((i<n1)&&(version1[i]!='.')){
                number1=number1*10+(version1[i]-'0');
                i++;
            }
            while((j<n2)&&(version2[j]!='.')){
                number2=number2*10+(version2[j]-'0');
                j++;
            }
            if(number1<number2){
                return -1;
            }
            else if(number1>number2){
                return 1;
            }
            else{
                i++;
                j++;
            }
            number1=0;
            number2=0;
        }
        return 0;
    }
};