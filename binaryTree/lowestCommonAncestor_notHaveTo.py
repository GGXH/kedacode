from treeUtil import node
from treeUtil import nodeBuilder

def lowestCommonAncestorHelper(nd, val1, val2):
  if nd is None:
    return None, 0
    
  m = 1 if nd.val == val1 or nd.val == val2 else 0
  leftRes, mL = lowestCommonAncestorHelper(nd.left, val1, val2)
  if mL == 2:
    return leftRes, mL
  m += mL
  if m == 2:
    return nd, m
  
  rightRes, mR = lowestCommonAncestorHelper(nd.right, val1, val2)
  if mR == 2:
    return rightRes, mR
  m += mR
  if m == 2:
    return nd, m

  return (leftRes, m) if leftRes is not None else (rightRes, m)
  
def lowestCommonAncestor(nd, val1, val2):
  res, m = lowestCommonAncestorHelper(nd, val1, val2)
  return res if m == 2 else None
    
  
  
if __name__ == "__main__":
  val = [0, 1, 2, None, None, 3, 4, None, None, None, None, None, None, None, 5]
  nd = nodeBuilder.deserialized(val)
  res = lowestCommonAncestor(nd, 3, 6)
  print res.val if res is not None else "NULL"
  
  val = [0, 1, 2, 6, 8, 3, 4, 7, None, None, None, None, None, 100, 5]
  nd = nodeBuilder.deserialized(val)
  res = lowestCommonAncestor(nd, 5, 2)
  print res.val if res is not None else "NULL"
  
  res = lowestCommonAncestor(nd, 1, 2)
  print res.val if res is not None else "NULL"
  
  res = lowestCommonAncestor(nd, 5, 4)
  print res.val if res is not None else "NULL"
