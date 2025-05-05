//To write a menu driven program for searching

#include <stdio.h>
#include "sort.h"

void input(int arr[],int);
int linear(int arr[],int,int);
int binary(int arr[],int,int);

int main()
{
    int len,choice;
    printf("\nEnter the length of the list : ");
    scanf("%d",&len);
    int arr[len];
    input(arr,len);
    printf("\n<=======Menu=======>\n");
    printf("\n1.Linear Search\n");
    printf("2.Binary Search\n");
    printf("3.Exit\n");
    printf("\nEnter a choice to : ");
    scanf("%d",&choice);
    
    while(choice<1 || choice>3)
    {
        printf("Invalid Choice!!\n");
        printf("\nEnter a choice to : ");
        scanf("%d",&choice);
    }
    
    while(choice!=3)
    {
        if(choice==1)
        {
            int num;
            printf("\nEnter a number to search : ");
            scanf("%d",&num);
            int found=linear(arr,len,num);

            if(found>0)
            {
                printf("\nThe element %d is found %d times in the array.\n",num,found);
            }

            else
            {
                printf("\nThe element %d is not found in the array.\n",num);
            }
        }

        else if(choice==2)
        {
            int num;
            printf("\nEnter a number to search : ");
            scanf("%d",&num);
            int found=binary(arr,len,num);

            if(found>0)
            {
                printf("\nThe element %d is found %d times in the array.\n",num,found);
            }

            else
            {
                printf("\nThe element %d is not found in the array.\n",num);
            }
        }

        else
        {
            printf("\nExit!\n");
        }

        printf("\n<=======Menu=======>\n");
        printf("\n1.Linear Search\n");
        printf("2.Binary Search\n");
        printf("3.Exit\n");
        printf("\nEnter a choice : ");
        scanf("%d",&choice);
        while(choice<1 || choice>3)
        {
            printf("Invalid Choice!!\n");
            printf("\nEnter a choice to : ");
            scanf("%d",&choice);
        }
    }
}

void input(int arr[],int len){
    printf("\n");
    
    for(int i=0;i<len;i++){
        printf("\nEnter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
}

int linear(int arr[],int len,int num)
{
    int count=0;
    for(int i=0;i<len;i++)
    {
        if(arr[i]==num)
        {
            printf("\nThe Element %d is found at the index %d\n",num,i);
            count++;
        }
    }
    return count;
}

int binary(int arr[],int len,int num)
{
    int choice;
    printf("\n<=======Menu=======>\n");
    printf("\n1.Bubble Sort\n");
    printf("2.Selection Sort\n");
    printf("3.Insertion Sort\n");
    printf("\nEnter a choice to : ");
    scanf("%d",&choice);
    
    while(choice<1 || choice>3)
    {
        printf("Invalid Choice!!\n");
        printf("\n<=======Menu=======>\n");
        printf("\n1.Bubble Sort\n");
        printf("2.Selection Sort\n");
        printf("3.Insertion Sort\n");
        printf("\nEnter a choice to : ");
        scanf("%d",&choice);
    }
    
    switch(choice){
        case 1:
            bubble(arr,len);
            break;
        
        case 2:
            selection(arr,len);
            break;

        case 3:
            insertion(arr,len);
            break;
            
        default:
            printf("Invalid Choice!\n");
            break;
    }

    int count=0;
    
    if(num<arr[len/2])
    {
        for(int i=0;i<len/2;i++)
        {
            if(num==arr[i])
            {
                printf("\nThe element %d is found at the index %d.\n",num,i);
                count++;
            }
        }
    }

    else if(num>arr[len/2])
    {
        for(int i=(len/2)+1;i<len;i++)
        {
            if(num==arr[i])
            {
                printf("\nThe element %d is found at the index %d.\n",num,i);
                count++;
            }
        }
    }

    else if(num==arr[len/2])
    {
        printf("\nThe element %d is found at the center index %d.\n",num,len/2);
        count++;
    }

    return count;
}