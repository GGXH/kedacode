def findksmallest(mat, k):
  if len(mat) == 0 or len(mat[0]) == 0:
    return -1
    
  mi = mat[0][0]
  ma = mat[-1][-1]
  
  while mi < ma:
    mid = mi + ( ma - mi ) / 2
    cnt = 0
    col = len(mat[0]) - 1
    for i in xrange(len(mat)):
      while col >= 0 and mat[i][col] > mid:
        col -= 1
      cnt += col + 1
    if cnt == k:
      return mid
    elif cnt > k:
      ma = mid - 1
    else:
      mi = mid + 1
  return mi


if __name__ == "__main__":
  input = [[1, 4, 7, 11, 15], [2, 5, 8, 12, 19], [3, 6, 9, 16, 22], [10, 13, 14, 17, 24], [18, 21, 23, 26, 30]]
  
  print findksmallest(input, 10)