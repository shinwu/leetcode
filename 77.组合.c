/*
 * @lc app=leetcode.cn id=77 lang=c
 *
 * [77] 组合
 */

// @lc code=start
void backtracking(int **ans, int *candidates, int n, int k, int *returnSize,
                  int **returnColumnSizes, int *used, int *path, int depth,
                  int index) {
  if (depth == k) {
    ans[*returnSize] = (int *)malloc(sizeof(int) * k);
    memcpy(ans[*returnSize], path, sizeof(int) * k);
    (*returnColumnSizes)[*returnSize] = k;
    (*returnSize)++;
    return;
  }

  for (int i = index; i < n; i++) {
    if (used[i] == 1) {
      continue;
    }
    path[depth++] = candidates[i];
    used[i] = 1;
    backtracking(ans, candidates, n, k, returnSize, returnColumnSizes, used,
                 path, depth, i);
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
int **combine(int n, int k, int *returnSize, int **returnColumnSizes) {
  *returnSize = 0;
  int **ans = (int **)malloc(sizeof(int *) * 100001);
  *returnColumnSizes = (int *)malloc(sizeof(int) * 100001);
  int *candidates = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    candidates[i] = i + 1;
  }
  int *used = (int *)malloc(sizeof(int) * n);
  int *path = (int *)malloc(sizeof(int) * k);
  backtracking(ans, candidates, n, k, returnSize, returnColumnSizes, used, path,
               0, 0);
  return ans;
}
// @lc code=end
