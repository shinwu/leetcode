/*
 * @lc app=leetcode.cn id=90 lang=c
 *
 * [90] 子集 II
 */

// @lc code=start
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void backtracking(int **ans, int *nums, int numsSize, int *returnSize,
                  int **returnColumnSizes, int *path, int index, int depth,
                  int *used) {
  for (int i = index; i < numsSize; i++) {
    if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] != 1) {
      continue;
    }

    path[depth++] = nums[i];
    used[i] = 1;

    ans[*returnSize] = (int *)malloc(sizeof(int) * depth);
    memcpy(ans[*returnSize], path, sizeof(int) * depth);
    (*returnColumnSizes)[*returnSize] = depth;
    (*returnSize)++;

    backtracking(ans, nums, numsSize, returnSize, returnColumnSizes, path,
                 i + 1, depth, used);
    depth--;
    used[i] = 0;
  }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **subsetsWithDup(int *nums, int numsSize, int *returnSize,
                     int **returnColumnSizes) {
  *returnSize = 0;
  int **ans = (int **)malloc(sizeof(int *) * 100001);

  *returnColumnSizes = (int *)malloc(sizeof(int) * 100001);
  int *path = (int *)malloc(sizeof(int) * numsSize);
  int *used = (int *)malloc(sizeof(int) * numsSize);

  ans[*returnSize] = (int *)malloc(sizeof(int) * 0);
  memcpy(ans[*returnSize], path, sizeof(int) * 0);
  (*returnColumnSizes)[*returnSize] = 0;
  (*returnSize)++;

  qsort(nums, numsSize, sizeof(int), cmp);
  backtracking(ans, nums, numsSize, returnSize, returnColumnSizes, path, 0, 0,
               used);
  return ans;
}
// @lc code=end
