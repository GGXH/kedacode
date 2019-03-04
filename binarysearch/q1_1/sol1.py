#search target in a sorted array, return index and return -1 if not found, no duplicate. example [1, 2, 4, 5, 7, 9], 7 -> 4
#if duplicate allowed, find the index of the first/last/total occurence

def firstOccur(arr, target):
  start = 0
  end = len(arr) - 1
  while start < end:
    mid = ( start + end ) / 2
    if arr[mid] == target:
      end = mid
    elif arr[mid] < target:
      start = mid + 1
    elif arr[mid] > target:
      end = mid - 1
  return start if arr[start] == target else -1
   
def lastOccur(arr, target):
  start = 0
  end = len(arr) - 1
  while start + 1 < end:
    mid = ( start + end ) / 2
    if arr[mid] == target:
      start = mid
    elif arr[mid] < target:
      start = mid + 1
    elif arr[mid] > target:
      end = mid - 1
  return start if arr[start] == target else -1
  
if __name__ == "__main__":
  input = [1, 2, 4, 5, 7, 7, 7, 9]
  target = 7
  
  print firstOccur(input, target)
  print lastOccur(input, target)