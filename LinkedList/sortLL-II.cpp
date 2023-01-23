// Link: https://practice.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1

// Approach: [TC: O(N)]

void sort(Node **head)
{
     Node* temp1 = *head;
     Node* temp2 = temp1->next;
     
     while(temp2 || temp1->next){
        if(temp1->data > temp2->data){
            swap(temp1->data,temp2->data);
        }
        temp2=temp2->next;
        if(temp2==NULL){
            temp1=temp1->next;
            temp2=temp1->next;
        }
     }
}