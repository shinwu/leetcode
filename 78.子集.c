/*
 * @lc app=leetcode.cn id=78 lang=c
 *
 * [78] 子集
 */

// @lc code=start
void backtracking(int **ans, int *nums, int numsSize, int *returnSize,
                  int **returnColumnSizes, int *path, int index, int depth) {
  for (int i = index; i < numsSize; i++) {
    path[depth++] = nums[i];

    ans[*returnSize] = (int *)malloc(sizeof(int) * depth);
    memcpy(ans[*returnSize], path, sizeof(int) * depth);
    (*returnColumnSizes)[*returnSize] = depth;
    (*returnSize)++;

    backtracking(ans, nums, numsSize, returnSize, returnColumnSizes, path,
                 i + 1, depth);
    depth--;
  }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **subsets(int *nums, int numsSize, int *returnSize,
              int **returnColumnSizes) {
  *returnSize = 0;
  int **ans = (int **)malloc(sizeof(int *) * 100001);

  *returnColumnSizes = (int *)malloc(sizeof(int) * 100001);
  int *path = (int *)malloc(sizeof(int) * numsSize);

  ans[*returnSize] = (int *)malloc(sizeof(int) * 0);
  memcpy(ans[*returnSize], path, sizeof(int) * 0);
  (*returnColumnSizes)[*returnSize] = 0;
  (*returnSize)++;

  backtracking(ans, nums, numsSize, returnSize, returnColumnSizes, path, 0, 0);
  return ans;
}
// @lc code=end
