def kthsmallestNo(input1, input2, k):
#  print input1, input2, k
  if k > len(input1) + len(input2) or k < 0:
     return -1
     
  if len(input1) < len(input2):
     return kthsmallestNo(input2, input1, k)
     
  if len(input2) == 0:
     return input1[k-1]
     
  if k == 1:
     return min(input1[0], input2[0])
  
  i = min(len(input1) - 1, k / 2 - 1)
  j = min(len(input2) - 1, k / 2 - 1)
  
  if input1[i] < input2[j]:
     return kthsmallestNo(input1[i+1:], input2, k - i - 1)
  else:
     return kthsmallestNo(input1, input2[j+1:], k - j - 1)
  
  
if __name__ == "__main__":
  input1 = [1, 2, 3, 4, 8, 9]
  input2 = [2.5, 7]
  
  print kthsmallestNo(input1, input2, 5)
  print kthsmallestNo(input2, input1, 5)