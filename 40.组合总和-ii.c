/*
 * @lc app=leetcode.cn id=40 lang=c
 *
 * [40] 组合总和 II
 */

// @lc code=start
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void backtracking(int **ans, int *candidates, int candidatesSize, int target,
                  int *returnSize, int **returnColumnSizes, int depth,
                  int index, int sum, int *used, int *path) {
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

    if (used[i] == 1 || i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] != 1) {
      continue;
    }

    sum += candidates[i];
    path[depth++] = candidates[i];
    used[i] = 1;
    backtracking(ans, candidates, candidatesSize, target, returnSize,
                 returnColumnSizes, depth, i, sum, used, path);
    sum -= candidates[i];
    used[i] = 0;
    depth--;
  }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **combinationSum2(int *candidates, int candidatesSize, int target,
                      int *returnSize, int **returnColumnSizes) {
  *returnSize = 0;
  int **ans = (int **)malloc(sizeof(int *) * 100001);
  *returnColumnSizes = (int *)malloc(sizeof(int *) * 100001);
  int *used = (int *)malloc(sizeof(int) * candidatesSize);
  int *path = (int *)malloc(sizeof(int) * 100001);
  qsort(candidates, candidatesSize, sizeof(int), cmp);
  backtracking(ans, candidates, candidatesSize, target, returnSize,
               returnColumnSizes, 0, 0, 0, used, path);
  return ans;
}
// @lc code=end
