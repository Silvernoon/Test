/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。

示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5

提示：

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

#include <stdlib.h>
#include <stdio.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size);

int main()
{
    int a[2] = {1, 3};
    int b[2] = {2};
    printf("%f", findMedianSortedArrays(a, 2, b, 1));
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int sumSize = nums1Size + nums2Size;
    int *sum = (int *)malloc(sizeof(int) * sumSize);

    // i为数组1下标， j为数组2下标，k为总数组下标
    int i = 0, j = 0, k = 0;
    while (k < sumSize)
    {
        switch ((i < nums1Size) + (j < nums2Size) * 2)
        {
        case 1:
            goto C;
        case 2:
            goto B;
        case 3:
            goto A;
        default:
            break;
        }

        if (0)
        {
        A:
            if (nums1[i] <= nums2[j])
            {
            C:
                sum[k] = nums1[i];
                i++;
            }
            else
            {
            B:
                sum[k] = nums2[j];
                j++;
            }
        }

        k++;
    }

    double ret;
    if (sumSize % 2) // 奇数
        ret = (double)sum[(sumSize + 1) / 2 - 1];
    else // 偶数
        ret = (double)(sum[sumSize / 2 - 1] + sum[sumSize / 2]) / 2;
    free(sum);
    return ret;
}