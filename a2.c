#include <stdio.h>

void swap(int *a, int *b){
    int t=*a;
    *a = *b;
    *b = t;
}

void printarray(int a[], int n){
   for (int i = 0; i < n; i++)
   {
       printf("%d ", a[i]);
   }
}

int partition (int a[], int lowIndex, int highIndex) 
{ 
int pivotElement = a[highIndex];
int i = (lowIndex - 1); 
for (int j = lowIndex; j <= highIndex- 1; j++) 
{ 
if (a[j] <= pivotElement) 
{ 
i++; 
swap(&a[i], &a[j]); 
} 
} 
swap(&a[i + 1], &a[highIndex]); 
return (i + 1); 
 }

void merge(int a[], int l, int m, int r) 
{ 
int i, j, k; 
int n1 = m - l + 1; 
int n2 =  r - m; 
int L[n1], R[n2]; 
for (i = 0; i < n1; i++) 
L[i] = a[l + i]; 
for (j = 0; j < n2; j++) 
R[j] = a[m + 1+ j]; 
i = 0; 
j = 0; 
k = l; 
while (i < n1 && j < n2) { 
if (L[i] <= R[j]) { 
a[k] = L[i]; 
i++; 
} 
else
{ 
a[k] = R[j]; 
j++; 
} 
k++; 
} 
while (i < n1) { 
a[k] = L[i]; 
i++; 
k++; 
} 
while (j < n2) { 
a[k] = R[j]; 
j++; 
k++; 
} 
}

// Bubble sort method
void bubblesort(int a[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j+1] < a[j])
            swap(&a[j], &a[j+1]);
        }
    }
    printf("Sorted array is: ");
    printarray(a, n);
     
}
// Selection sort
void selectionsort(int a[], int n){
    int t=0;
    int s;
    for(int i = 0; i<n-1; i++){
        s=a[i];
        for(int j=i; j<n; j++){
            if (a[j]<s)
            {
                s = a[j];
                t=j;
                swap(&a[t], &a[i]);
            }
        }
    }
    printf("Sorted array is: ");
    printarray(a, n); 
}

void insertionSort(int a[], int n) 
{ 
int i, element, j; 
for (i = 1; i < n; i++){
    element = a[i]; j = i - 1;
     while (j >= 0 && a[j] > element) { 
     a[j + 1] = a[j]; 
     j = j - 1; 
      } 
    a[j + 1] = element; 
}
printf("Sorted array is: ");
    printarray(a, n);
}

void quickSort(int a[], int lowIndex, int highIndex) 
{ 
if (lowIndex < highIndex) 
{ 
int pivot = partition(a, lowIndex, highIndex); 
// Separately sort elements before & after partition 
quickSort(a, lowIndex, pivot - 1); 
quickSort(a, pivot + 1, highIndex); 
}
}

void mergeSort(int a[], int l, int r) 
{ 
if (l < r) 
{ 
int m = l+(r-l)/2; 
mergeSort(a, l, m); 
mergeSort(a, m+1, r); 
merge(a, l, m, r); 
}

} 

int main(){

    int a[] = {2, 5, 10, 16, 12, 9, 8};
    int n = sizeof(a)/sizeof(a[0]);
    int choice;
    printf("Enter 1 to sort by bubblesort method.\n");
    printf("Enter 2 to sort by selection sort method.\n");
    printf("Enter 3 to sort by insertion sort method.\n");
    printf("Enter 4 to sort by quick sort method.\n");
    printf("Enter 5 to sort by merge sort method.\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        bubblesort(a, n);
        break;
    case 2:
        selectionsort(a,n);
        break;
    case 3:
        insertionSort(a, n);
        break;
    case 4:
        quickSort(a,0, n-1);
        printf("Sorted array is: ");
        printarray(a, n);
        break;
    case 5:
       mergeSort(a, 0,n - 1);
       printf("Sorted array is: ");
       printarray(a, n);
        break;

    }

    return 0;
}