#include <stdio.h>
#include <stdlib.h>

int *sort(int *nums, int numsSize);

typedef enum
{
    RED,
    BLACK
} NodeColor;

typedef struct
{
    int data;
    NodeColor color;
    struct RBTreeNode *left, *right, *parent;
} RBTreeNode;

typedef struct
{
    RBTreeNode *root;
    RBTreeNode *nil;
} RBTree;

int main()
{
    int s[4] = {2, 7, 15, 11};

    int *out = sort(s, 4);

    for (int i = 0; i <= 4-1; i++)
    {
        printf("%i\t", out[i]);
    }
    
    
    return 0;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    nums[numsSize] = target;
    return nums;
}

// ÅÅÐò
int *sort(int *nums, int numsSize)
{
    int min;  // ×îÐ¡Öµ
    int temp; // »º´æ
    for (int i = 0; i < numsSize - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[j] < nums[min])
                min = j;
        }
        if (min != i)
        {
            temp = nums[i];
            nums[i] = nums[min];
            nums[min] = temp;
        }
    }
    return nums;
}