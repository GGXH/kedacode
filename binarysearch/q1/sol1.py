#search target in a sorted array, return index and return -1 if not found, no duplicate. example [1, 2, 4, 5, 7, 9], 7 -> 4

def binarySearch(arr, target):
  start = 0
  end = len(arr) - 1
  while start < end:
    mid = ( start + end ) / 2
    if arr[mid] == target:
      return mid
    elif arr[mid] < target:
      start = mid + 1
    elif arr[mid] > target:
      end = mid - 1
  return -1
  
if __name__ == "__main__":
  input = [1, 2, 4, 5, 7, 9]
  target = 8
  
  print binarySearch(input, target)