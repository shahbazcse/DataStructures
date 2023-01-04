// Link: https://www.codingninjas.com/codestudio/problems/swap-alternate_624941

void swapAlternate(int *arr, int size)
{
    for(int i=1; i<size; i++){
        int temp = arr[i-1];
        arr[i-1] = arr[i];
        arr[i] = temp;
        i++;
    }
}