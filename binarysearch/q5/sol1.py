#Search the target in a rotated matrix, return position and return [-1, -1] if not found Assume no duplicate.  In the matrix, always has M[i][j] < M[i][j+1] and M[i][j] < M[i+1][j]

def searchSortedMat(mat, target):
  if len(mat) == 0 or len(mat[0]) == 0:
    return (-1, -1)
  return searchSortedMatHelp(mat, target, 0, len(mat[0]) - 1, 0, len(mat) - 1)
  
  
def searchSortedMatHelp(mat, target, left, right, up, bot):
   if left > right or up > bot:
      return (-1, -1)
      
   width = right - left + 1
   height = bot - up + 1
   midrow = up + height / 2
   midcol = left + width / 2
   if mat[midrow][midcol] == target:
     return (midrow, midcol)
   if mat[midrow][midcol] > target:
     result1 = searchSortedMatHelp(mat, target, midcol, right, up, midrow - 1)
     result2 = searchSortedMatHelp(mat, target, left, midcol - 1, up, bot)
   else:
     result1 = searchSortedMatHelp(mat, target, left, midcol, midrow + 1, bot)
     result2 = searchSortedMatHelp(mat, target, midcol + 1, right, up, bot)
   if result1[0] != -1:
     return result1
   if result2[0] != -1:
     return result2
   return (-1, -1)
   
   
if __name__ == "__main__":
  input = [[1, 4, 7, 11, 15], [2, 5, 8, 12, 19], [3, 6, 9, 16, 22], [10, 13, 14, 17, 24], [18, 21, 23, 26, 30]]
  
  print searchSortedMat(input, 12.5)