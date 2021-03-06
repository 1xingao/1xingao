from typing import List

#寻找山峰数组的山峰
#二分查找
def peakIndexInMountainArray( arr: List[int]) -> int:
    left,right = -1,len(arr)
    while left <=right:
        mid = left + (right-left)//2
        if arr[mid] < arr[mid-1]:
            right = mid -1
        else:
            left = mid +1
    return right

data_list = [1,3,5,4,2,1]
c=peakIndexInMountainArray(data_list)
print(c)
#二分查找算法的边界left和right一一对应
#