// 选择排序 和插入排序
#include <cstdio>
#include <algorithm>
#include <vector>

void selectSort(std::vector<int> &A)
{
    int n = A.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[minIndex])
            {
                minIndex = j;
            }
        };
        if (minIndex != i)
        {
            std::swap(A[i], A[minIndex]);
        }
    }
}
void insertSort(std::vector<int>&  arr) {
    int n = arr.size();
    for(int i=1;i<n;i++) {
        int temp = arr[i],j=i;
        while(j>0 && temp > arr[j-1]) {
            arr[j] = arr[j-1];   //把前面的往后挪
            j--;
        }
        arr[j] = temp;
    }
}


int main()
{
    std::vector<int> arr = {64, 25, 12, 22, 11};
    selectSort(arr);
    printf("选择排序后输出的数组：");
    for (int i = 0; i < arr.size(); i++)
    {
        printf("%d ", arr[i]);
    }
    insertSort(arr);
    printf("插入排序后输出的数组：");
    for (int i = 0; i < arr.size(); i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}