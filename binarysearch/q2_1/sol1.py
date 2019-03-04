#search k closest target in a sorted array, return index, no duplicate. example [1, 2, 4, 5, 7, 9], 6 -> 3


def searchClosest(arr, target, k):
  start = 0
  end = len(arr) - 1
  while start + 1 < end:
    mid = ( start + end ) / 2
    if arr[mid] == target:
      start = mid
      break
    elif arr[mid] < target:
      start = mid
    elif arr[mid] > target:
      end = mid
  pivot = start if target - arr[start] <= arr[end] - target else end
  res = [pivot]
  start = pivot - 1
  end = pivot + 1
  while len(res) < k and ( start >= 0 or end < len(arr)):
    if start < 0:
      res.append(end)
      end += 1
      continue
    if end >= len(arr):
      res.append(start)
      start -= 1
      continue
    if target - arr[start] <= arr[end] - target:
      res.append(start)
      start -= 1
    else:
      res.append(end)
      end += 1
  return res
  
  
if __name__ == "__main__":
  input = [1, 2, 4, 5, 7, 9]
  
  print searchClosest(input, 7, 4)
  print searchClosest(input, 6, 3)
  print searchClosest(input, 10, 5)
  print searchClosest(input, 1.1, 6)