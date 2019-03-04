#search closest target in a sorted array, return index, no duplicate. example [1, 2, 4, 5, 7, 9], 6 -> 3

def searchClosest(arr, target):
  start = 0
  end = len(arr) - 1
  while start + 1 < end:
    mid = ( start + end ) / 2
    if arr[mid] == target:
      return mid
    elif arr[mid] < target:
      start = mid
    elif arr[mid] > target:
      end = mid
  return start if target - arr[start] <= arr[end] - target else end
  
if __name__ == "__main__":
  input = [1, 2, 4, 5, 7, 9]
  
  print searchClosest(input, 7)
  print searchClosest(input, 6)
  print searchClosest(input, 10)
  print searchClosest(input, 1.1)