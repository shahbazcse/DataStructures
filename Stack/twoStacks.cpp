// Link: https://practice.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1

// Approach: [TC: O(1) / SC: O(1)]

//Function to push an integer into the stack1
void twoStacks :: push1(int x)
{
    if(top2-top1>1){
        top1++;
        arr[top1]=x;
        return;
    }
}
   
//Function to push an integer into the stack2
void twoStacks ::push2(int x)
{
    if(top2-top1>1){
        top2--;
        arr[top2]=x;
        return;
    }
}
   
//Function to remove an element from top of the stack1
int twoStacks ::pop1()
{
    if(top1>=0){
        return arr[top1--];
    }else return -1;
}

//Function to remove an element from top of the stack2
int twoStacks :: pop2()
{
    if(top2<size){
        return arr[top2++];
    }else return -1;
}