from treeUtil import node
from treeUtil import nodeBuilder

def isSameTree(nd1, nd2):
  if nd1 is None and nd2 is None:
    return True
  if nd1 is None or nd2 is None:
    return False
  if nd1.val != nd2.val:
    return False
  return isSameTree(nd1.left, nd2.left) and isSameTree(nd1.right, nd2.right)


def isSubtree(nd1, nd2):
  if nd1 is None and nd2 is None:
    return True
  if nd1 is None or nd2 is None:
    return False
  return isSameTree(nd1, nd2) or isSubtree(nd1.left, nd2) or isSubtree(nd1.right, nd2)
  
  
if __name__ == "__main__":
  val1 = [0, 1, 2, None, None, 3, 4, None, None, None, None, None, None, None, 5]
  val2 = [2, 3, 4]
  nd1 = nodeBuilder.deserialized(val1)
  nd2 = nodeBuilder.deserialized(val2)
  print isSubtree(nd1, nd2)
  
  val1 = [0, 1, 2, 6, 8, 3, 4, 7, None, None, None, None, None, None, 5]
  val2 = [2, 3, 4, None, None, None, 5]
  nd1 = nodeBuilder.deserialized(val1)
  nd2 = nodeBuilder.deserialized(val2)
  print isSubtree(nd1, nd2)
  