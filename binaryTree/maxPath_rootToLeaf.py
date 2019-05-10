from treeUtil import node
from treeUtil import nodeBuilder

def maxPath(nd):
  if nd is None:
    return 0
    
  maxLeft = maxPath(nd.left)
  maxRight = maxPath(nd.right)
  
  return max(maxLeft, maxRight) + nd.val
 
  
  
if __name__ == "__main__":
  val = [0, 1, 2, None, None, 3, 4, None, None, None, None, None, None, None, 5]
  nd = nodeBuilder.deserialized(val)
  print maxPath(nd)
  
  val = [0, 1, 2, 6, 8, 3, 4, 7, None, None, None, None, None, 100, 5]
  nd = nodeBuilder.deserialized(val)
  print maxPath(nd)
