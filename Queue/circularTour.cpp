// Link: https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1

// Approach: 2 Pointer [TC: O(N) / SC: O(1)]

/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};
*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int prev_petrol = 0;
       int curr_petrol = 0;
       int start = 0;
       
       for(int i=0; i<n; i++){
           curr_petrol += p[i].petrol - p[i].distance;
           if(curr_petrol < 0){
               prev_petrol += curr_petrol;
               start = i+1;
               curr_petrol = 0;
           }
       }
       
       if(prev_petrol + curr_petrol >= 0) return start;
       else return -1;
    }
};