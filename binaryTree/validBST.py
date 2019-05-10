from treeUtil import node
from treeUtil import nodeBuilder

def validBSTHelper(nd):
  if nd is None:
    return True, None, None
  
  minV = nd.val
  maxV = nd.val
  if nd.left is not None:
    valL, minL, maxL = validBSTHelper(nd.left)
    if not valL:
      return valL, minV, maxV
    if maxL is not None and nd.val < maxL:
      return False, minV, maxV
    minV = min(minV, minL)
  
  if nd.right is not None:
    valR, minR, maxR = validBSTHelper(nd.right)
    if not valR:
      return valR, minV, maxV
    if maxR is not None and nd.val > minR:
      return False, minV, maxV
    maxV = max(maxV, maxR)
  return True, minV, maxV
 

def validBST(nd):
  val, _, _ = validBSTHelper(nd)
  return val
  
  
  
if __name__ == "__main__":
  val = [5, 4, 6, 3, 4.5, 5.5, 7]
  nd = nodeBuilder.deserialized(val)
  print validBST(nd)
  
  val = [5, 4, 6, 3, 4.5, 5.5, 7, 8]
  nd = nodeBuilder.deserialized(val)
  print validBST(nd)
  