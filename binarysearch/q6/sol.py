def sqrt(num):
  if num < 0:
    return -1
    
  left = 1
  right = num / 2 + 1
  while left < right:
    mid = left + ( right - left ) / 2
    if mid * mid <= num and ( mid + 1 ) * ( mid + 1 ) >= num:
      return mid
    else:
      if mid * mid < num:
        left = mid + 1
      else:
        right = mid
  return left
   
if __name__ == "__main__":
  print sqrt(2)
  print sqrt(100)
  print sqrt(126)