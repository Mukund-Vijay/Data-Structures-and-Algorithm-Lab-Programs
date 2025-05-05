//To write a menu driven program for sorting

#include <stdio.h>

void bubble(int arr[],int);
void insertion(int arr[],int);
void selection(int arr[],int);
void input(int arr[],int);
void display(int arr[],int);

int main(){
    int len,choice;
    printf("\nEnter the length of the list : ");
    scanf("%d",&len);
    int arr[len];
    input(arr,len);
    printf("\nThe unsorted array is : ");
    display(arr,len);
    printf("\n<=======Menu=======>\n");
    printf("\n1.Bubble Sort\n");
    printf("2.Selection Sort\n");
    printf("3.Insertion Sort\n");
    printf("4.Exit\n");
    printf("\nEnter a choice : ");
    scanf("%d",&choice);

    while(choice!=4)
    {
        switch(choice){
            case 1:
                bubble(arr,len);
                printf("\nThe sorted array is : ");
                display(arr,len);
                break;
        
            case 2:
                selection(arr,len);
                printf("\nThe sorted array is : ");
                display(arr,len);
                break;

            case 3:
                insertion(arr,len);
                printf("\nThe sorted array is : ");
                display(arr,len);
                break;
            
            case 4:
                printf("\nExit!\n");
                break;
            
            default:
                printf("Invalid Choice!\n");
                break;
        }

        printf("\n<=======Menu=======>\n");
        printf("\n1.Bubble Sort\n");
        printf("2.Selection Sort\n");
        printf("3.Insertion Sort\n");
        printf("4.Exit\n");
        printf("\nEnter a choice : ");
        scanf("%d",&choice);
    }
}

void input(int arr[],int len){
    printf("\n");
    
    for(int i=0;i<len;i++){
        printf("\nEnter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
}

void display(int arr[],int len){
    
    for(int i=0;i<len;i++){
        printf("%d\t",arr[i]);
    }

    printf("\n");
}

void bubble(int arr[],int len){
    for(int i=0;i<len;i++){
        for(int j=0;j<len-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void selection(int arr[],int len){
    for(int i=0;i<len;i++)
    {
        int min_index=i;
        
        for(int j=i+1;j<len;j++)
        {
            if(arr[min_index]>arr[j]){
                min_index=j;
            }
        }
        
        int temp=arr[min_index];
        arr[min_index]=arr[i];
        arr[i]=temp;
    }
}

void insertion(int arr[],int len){
    for(int i=0;i<len;i++){
        while(arr[i]<arr[i-1] && i>0){
            int key=arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=key;
            i-=1;
        }
    }
}