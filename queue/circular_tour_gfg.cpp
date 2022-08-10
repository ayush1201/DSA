class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       //we will be using queue and if present to next travel is possible then rear++.
       //else front = rear+1.
       //if front==rear cycle complete.
       //agar kisi ek block se next pe nhi pahuch pare to uske phele ke kisi se bhi nhi pahuchenge isliye front++ nhi kia aur faltu iteration bachaya hai.
       
       int deficit=0;
       int balance=0;
       int start=0;
       
       for(int i=0;i<n;i++){
           balance +=p[i].petrol - p[i].distance;
           if(balance<0){
               deficit+=balance;
               start = i+1;
               balance=0;
               
           }
       }
           if(deficit + balance<0){
               return -1;
           }
           else{
               return start;
           }
       
       
    }
};