#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if (nums1 == NULL || nums2 == NULL)
    {
        return -1;
    }
    float *newarray = NULL;
    newarray = (float*) malloc(sizeof(float) * (nums1Size + nums2Size));
    if (newarray == NULL)
    {
        return -2;
    }
    
    int i = 0;
    int j = 0;
   
    int k = 0;
   
    while((j < nums2Size) && (i < nums1Size))
    {
        if(*(nums1 + i) < *(nums2 + j))
        {
           
           *(newarray+k)= *(nums1+i);
           k++;
           i++;
        }
        else if(*(nums1+i) > *(nums2+j))
        {
           *(newarray+k) = *(nums2 + j);
           k++;
           j++;
            
        }
        else
        {
            /* same */
            *(newarray+k) = *(nums2 + j);
            k++;
            *(newarray+k) = *(nums1 + i);
            k++;
            i++;
            j++;
        }
    }
    /* we reached the end here then one array has ended 
       the larger array will then just be added to the end \
     */
    printf("i=%d,j=%d,k=%d\n",i,j,k);
    if (j == nums2Size)
    {
        //j has ended
        while(i < nums1Size)
        {
            *(newarray + k) = *(nums1 + i);
            i++;
            k++;
        }
    }
    else if (i == nums1Size)
    {
        //i has ended
        while(j < nums2Size)
        {
            *(newarray + k) = *(nums2 + j);
            j++;
            
            printf("j=%d,k=%d,val=%d\n",j,k, *(newarray+k));
            k++;
        }
    }
    int m = k - 1;
    int n = 0;
    for (n = 0; n <= m; n++)
    {
      printf("%f\n", *(newarray+n));
    }
    if (k % 2 == 0)
    {
        printf("k=%d,res=%f,%d,%d\n", k, (*(newarray + ((k/2)-1)) + *(newarray + (k/2)))/2, *(newarray + ((k/2)-1)),*(newarray + (k/2)));
        return((*(newarray + ((k/2)-1)) + *(newarray + (k/2)))/2);
    }
    else
    {
        m = k/2;
        printf("m=%d, res1=%f\n",m,*(newarray+m));
        return (*(newarray+m));
    }
}

int main()
{
  int arr1[] = {1,3,5,6,7,8,9,89};
  int arr2[] = {2,2,34,35,36,77,90,101,123,124};
  
  
  findMedianSortedArrays(arr1,8,arr2,10);
}
