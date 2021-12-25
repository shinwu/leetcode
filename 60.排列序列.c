/*
 * @lc app=leetcode.cn id=60 lang=c
 *
 * [60] 排列序列
 */

// @lc code=start
void permute(int **ans, int *candidates, int n, int *returnSize, int *used,
             int *path, int index, int k) {
  if (*returnSize == k) {
    return;
  }
  if (index == n) {
    ans[*returnSize] = (int *)malloc(sizeof(int) * n);
    memcpy(ans[*returnSize], path, sizeof(int) * n);
    (*returnSize)++;

    return;
  }

  for (int i = 0; i < n; i++) {
    if (used[i] == 1) {
      continue;
    }

    path[index] = candidates[i];
    used[i] = 1;
    permute(ans, candidates, n, returnSize, used, path, index + 1, k);
    used[i] = 0;
  }
}

char *getPermutation(int n, int k) {
  int *candidates = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    candidates[i] = i + 1;
  }

  int *returnSize = (int *)malloc(sizeof(int) * 1);
  *returnSize = 0;
  int **ans = (int **)malloc(sizeof(int *) * 400001);
  int *used = (int *)malloc(sizeof(int) * n);
  int *path = (int *)malloc(sizeof(int) * n);
  permute(ans, candidates, n, returnSize, used, path, 0, k);

  char *s = (char *)malloc(sizeof(char) * (n + 1));
  int offset = 0;
  for (int i = 0; i < n; i++) {
    offset += sprintf(s + offset, "%d", ans[k - 1][i]);
  }
  s[offset] = '\0';
  return s;
}
// @lc code=end
