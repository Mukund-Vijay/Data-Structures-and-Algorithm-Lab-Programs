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