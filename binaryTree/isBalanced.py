from treeUtil import node
from treeUtil import nodeBuilder

def balanceHelper(nd):
  if nd is None:
    return 0

  leftH = balanceHelper(nd.left)
  rightH = balanceHelper(nd.right)
  
  if leftH == -1 or rightH == -1 or abs(leftH - rightH) > 1:
     return -1
  
  return max(leftH, rightH) + 1
 

def isBalanced(nd):
  return balanceHelper(nd) != -1
  
  
  
if __name__ == "__main__":
  val = [0, 1, 2, None, None, 3, 4, None, None, None, None, None, None, None, 5]
  nd = nodeBuilder.deserialized(val)
  print isBalanced(nd)
  
  val = [0, 1, 2, 6, 8, 3, 4, 7, None, None, None, None, None, None, 5]
  nd = nodeBuilder.deserialized(val)
  print isBalanced(nd)
  