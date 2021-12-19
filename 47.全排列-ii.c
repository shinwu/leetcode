/*
 * @lc app=leetcode.cn id=47 lang=c
 *
 * [47] 全排列 II
 */

// @lc code=start
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void backtracking(int **ans, int *nums, int depth, int *returnSize,
                  int **returnColumnSizes, int *used, int *path, int index) {
  if (index == depth) {
    ans[*returnSize] = (int *)malloc(sizeof(int) * depth);
    memcpy(ans[*returnSize], path, sizeof(int) * depth);
    (*returnColumnSizes)[*returnSize] = depth;
    (*returnSize)++;
    return;
  }

  for (int i = 0; i < depth; i++) {
    if (used[i] == 1 || i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 1) {
      continue;
    }

    path[index] = nums[i];
    used[i] = 1;

    backtracking(ans, nums, depth, returnSize, returnColumnSizes, used, path,
                 index + 1);

    used[i] = 0;
  }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **permuteUnique(int *nums, int numsSize, int *returnSize,
                    int **returnColumnSizes) {
  qsort(nums, numsSize, sizeof(int), cmp);
  *returnSize = 0;
  int **ans = (int **)malloc(sizeof(int *) * 10001);
  *returnColumnSizes = (int *)malloc(sizeof(int) * 10001);
  int *used = (int *)malloc(sizeof(int) * numsSize);
  int *path = (int *)malloc(sizeof(int) * numsSize);
  backtracking(ans, nums, numsSize, returnSize, returnColumnSizes, used, path,
               0);
  return ans;
}
// @lc code=end
