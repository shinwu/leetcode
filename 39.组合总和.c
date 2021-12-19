/*
 * @lc app=leetcode.cn id=39 lang=c
 *
 * [39] 组合总和
 */

// @lc code=start
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void bachtracking(int **ans, int *candidates, int candidatesSize, int target,
                  int *returnSize, int **returnColumnSizes, int *path, int sum,
                  int depth, int index) {
  if (sum > target) {
    return;
  }

  if (sum == target) {
    ans[*returnSize] = (int *)malloc(sizeof(int) * depth);
    memcpy(ans[*returnSize], path, sizeof(int) * depth);
    (*returnColumnSizes)[*returnSize] = depth;
    (*returnSize)++;
    return;
  }

  for (int i = index; i < candidatesSize; i++) {
    if (sum > target) {
      break;
    }

    sum += candidates[i];
    path[depth++] = candidates[i];
    bachtracking(ans, candidates, candidatesSize, target, returnSize,
                 returnColumnSizes, path, sum, depth, i);
    sum -= candidates[i];
    depth--;
  }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **combinationSum(int *candidates, int candidatesSize, int target,
                     int *returnSize, int **returnColumnSizes) {
  *returnSize = 0;
  qsort(candidates, candidatesSize, sizeof(int), cmp);
  int **ans = (int **)malloc(sizeof(int *) * 100001);
  *returnColumnSizes = (int *)malloc(sizeof(int) * 100001);
  int *path = (int *)malloc(sizeof(int) * 500);
  bachtracking(ans, candidates, candidatesSize, target, returnSize,
               returnColumnSizes, path, 0, 0, 0);
  return ans;
}
// @lc code=end
