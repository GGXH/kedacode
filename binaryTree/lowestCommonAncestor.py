from treeUtil import node
from treeUtil import nodeBuilder

def lowestCommonAncestor(nd, val1, val2):
  if nd is None:
    return None
    
  if nd.val == val1 or nd.val == val2:
    return nd
  
  leftRes = lowestCommonAncestor(nd.left, val1, val2)
  rightRes = lowestCommonAncestor(nd.right, val1, val2)
  
  if leftRes is not None and rightRes is not None:
    return nd
  
  return leftRes if leftRes is not None else rightRes
  
  
if __name__ == "__main__":
  val = [0, 1, 2, None, None, 3, 4, None, None, None, None, None, None, None, 5]
  nd = nodeBuilder.deserialized(val)
  print lowestCommonAncestor(nd, 3, 6).val
  
  val = [0, 1, 2, 6, 8, 3, 4, 7, None, None, None, None, None, 100, 5]
  nd = nodeBuilder.deserialized(val)
  print lowestCommonAncestor(nd, 5, 2).val
