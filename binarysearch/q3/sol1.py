#Search a target in a sorted stream, in which provides a function get(int indx) to get a number or null if it exceed size of the stream

def searchStream(arr, target):
  left = 0
  right = 1
  while left <= right:
    while right >= len(arr):
      right = right - ( right - left ) / 2
    if arr[right] < target:
      left = right
      right *= 2
      continue
    mid = left + ( right - left ) / 2
    if arr[mid] == target:
      return mid
    elif arr[mid] < target:
      left = mid + 1
    else:
      right = mid - 1
  return None

  
  
if __name__ == "__main__":
  input = range(100)
  
  print searchStream(input, 56)