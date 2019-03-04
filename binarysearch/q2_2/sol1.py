#Given an integer array, in which each element has a adjacent duplicates except one. write a function to find that one. example [1, 1, 5, 5, 4, 3, 3, 2, 2] -> 4


def findNoneDup(arr):
  if len(arr) == 1:
    return arr[0]
  start = 0
  end = len(arr) - 1
  while start < end:
    mid = ( start + end ) / 2
    if mid % 2 == 0:
      if arr[mid] == arr[mid + 1]:
        start = mid + 2
      else:
        end = mid
    else:
      if arr[mid] == arr[mid - 1]:
        start = mid + 1
      else:
        end = mid
  return arr[start]
  
  
if __name__ == "__main__":
  input = [1, 1, 5, 5, 4, 4, 7, 3, 3, 2, 2]
  
  print findNoneDup(input)