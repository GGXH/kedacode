#Search a target in a rotated array, return index and return -1 if not found Assume no duplicate


def searchRotatedArr(arr, target):
  left = 0
  right = len(arr) - 1
  
  while left <= right:
    mid = left + ( right - left ) / 2
    if arr[mid] == target:
      return mid
      
    if target < arr[right] and arr[mid] > arr[right]:
      left = mid + 1
    elif target > arr[left] and arr[mid] < arr[left]:
      right = mid - 1
    else:
      if arr[mid] < target:
        left = mid + 1
      else:
        right = mid - 1
  return None

  
  
if __name__ == "__main__":
  input = range(50, 100) + range(1, 50)
  
  print searchRotatedArr(input, 1)