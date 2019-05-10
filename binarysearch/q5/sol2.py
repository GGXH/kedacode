#Search the target in a rotated matrix, return position and return [-1, -1] if not found Assume no duplicate.  In the matrix, always has M[i][j] < M[i][j+1] and M[i][j] < M[i+1][j]

def searchSortedMat(mat, target):
  left = 0
  right = len(mat) * len(mat[0])
  while left < right:
    mid = left + ( right - left ) / 2
    row = mid / len(mat[0])
    col = mid % len(mat[0])
    if mat[row][col] == target:
      return (row, col)
    elif mat[row][col] < target:
      left = mid + 1
    else:
      right = mid
  row = left / len(mat[0])
  col = left % len(mat[0])
  return (row, col) if row < len(mat) and col < len(mat[0]) and mat[row][col] == target else (-1, -1)
   
   
if __name__ == "__main__":
  input = [[1, 3,5, 7], [10, 11, 16, 20], [23, 30, 34, 50]]
  
  print searchSortedMat(input, 12)