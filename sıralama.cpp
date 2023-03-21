#include<stdio.h>
#define boyut 10

int binary_sort(int dizi[],int aranan){
	int l=0,r=boyut-1,x;
	while(l<r){
		x=(l+r)/2;
		if(aranan==dizi[x]) return 1;
		else if(aranan<dizi[x]) r=x-1;
		else l=x+1;
	}
	return 0;
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
        
        if (arr[j] <= pivot)
        {
            i++;    
            int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
        }
    }
    int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;
 
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
	int dizi[]={1,2,3,4,5,6,7,8,9};
	if(binary_sort(dizi,3)==1) printf("aranan deger bulundu.");
	quickSort(dizi,0,9);
	
	
}



