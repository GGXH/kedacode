from treeUtil import node
from treeUtil import nodeBuilder

def maxPathHelper(nd):
  if nd is None:
    return 0, 0
    
  maxLeft, maxPathLeft = maxPathHelper(nd.left)
  maxRight, maxPathRight = maxPathHelper(nd.right)
  
  maxPath = max([maxLeft, maxRight, maxLeft + nd.val, maxRight + nd.val, maxLeft + maxRight + nd.val, maxPathLeft, maxPathRight])
  maxPartialPath = max(maxLeft, maxRight) + nd.val
 
  return maxPartialPath, maxPath
 

def maxPath(nd):
  _, mP = maxPathHelper(nd)
  return mP
  
  
  
if __name__ == "__main__":
  val = [0, 1, 2, None, None, 3, 4, None, None, None, None, None, None, None, 5]
  nd = nodeBuilder.deserialized(val)
  print maxPath(nd)
  
  val = [0, 1, 2, 6, 8, 3, 4, 7, None, None, None, None, None, 100, 5]
  nd = nodeBuilder.deserialized(val)
  print maxPath(nd)
