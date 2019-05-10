#Search a minimum value in a rotated array, return index and return -1 if not found Assume no duplicate

def findRotatedMin(arr):
  if len(arr) == 0:
    return None
  if len(arr) == 1:
    return arr[0]
  left = 0
  right = len(arr) - 1
  while left < right:
    mid = left + ( right - left ) / 2
    if arr[left] < arr[right]:
      return arr[left]
    else:
      if arr[mid] > arr[right]:
        left = mid + 1
      else:
        right = mid
  return arr[left]
   
if __name__ == "__main__":
  input = range(50, 100) + range(10, 50)
  
  print findRotatedMin(input)