from treeUtil import node
from treeUtil import nodeBuilder

def maxPathHelper(nd):
  if nd is None:
    return 0, 0
    
  maxLeft, maxLeftLToL = maxPathHelper(nd.left)
  maxRight, maxRightLToL = maxPathHelper(nd.right)
  
  return max(maxLeft, maxRight) + nd.val, max([maxLeftLToL, maxRightLToL, maxLeft + maxRight + nd.val])
  
def maxPath(nd):
  _, mp = maxPathHelper(nd)
  return mp
 
  
  
if __name__ == "__main__":
  val = [0, 1, 2, None, None, 3, 4, None, None, None, None, None, None, None, 5]
  nd = nodeBuilder.deserialized(val)
  print maxPath(nd)
  
  val = [0, 1, 2, 6, 8, 3, 4, 7, None, None, None, None, None, 100, 5]
  nd = nodeBuilder.deserialized(val)
  print maxPath(nd)
