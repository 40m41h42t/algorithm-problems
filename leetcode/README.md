# Two Sum

https://leetcode.com/problems/two-sum/

思路：

假设它是顺序的表

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *minptr = *(nums), *maxptr = *(nums+numsSize-1);
    while(minptr<maxptr){
        sum = *(minptr)+*(maxptr);
        if(sum>target){
            --maxptr;
        }
        else if(sum<target){
            ++minptr;
        }
        else
            break;
    }
    int *ret = (int*)malloc(sizeof(int)*2);
    ret[0] = *(minptr), ret[1] = *(maxptr);
    return ret
}
```

出现了一系列的问题，比如没有考虑到两个数可以相等、两个数均为负数，发现输入并不是顺序的，这说明我还要手动排一次序