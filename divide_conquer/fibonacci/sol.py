def fib(n):
  if n == 1 or n == 2:
    return 1
    
  tmp1 = 1
  tmp2 = 1
  i = 3
  while i <= n:
    tmp1, tmp2 = tmp2, tmp1 + tmp2
    i += 1
  return tmp2
  
  
  
if __name__ == "__main__":
  for i in xrange(1, 11):
    print i, fib(i)