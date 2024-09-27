/*
����������С�ֱ�Ϊ m �� n �����򣨴�С�������� nums1 �� nums2�������ҳ���������������������� ��λ�� ��

�㷨��ʱ�临�Ӷ�Ӧ��Ϊ O(log (m+n)) ��

ʾ�� 1��

���룺nums1 = [1,3], nums2 = [2]
�����2.00000
���ͣ��ϲ����� = [1,2,3] ����λ�� 2
ʾ�� 2��

���룺nums1 = [1,2], nums2 = [3,4]
�����2.50000
���ͣ��ϲ����� = [1,2,3,4] ����λ�� (2 + 3) / 2 = 2.5

��ʾ��

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

    // iΪ����1�±꣬ jΪ����2�±꣬kΪ�������±�
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
    if (sumSize % 2) // ����
        ret = (double)sum[(sumSize + 1) / 2 - 1];
    else // ż��
        ret = (double)(sum[sumSize / 2 - 1] + sum[sumSize / 2]) / 2;
    free(sum);
    return ret;
}