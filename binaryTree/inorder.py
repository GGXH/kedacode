from treeUtil import node
from treeUtil import nodeBuilder

def inorder(nd):
  if nd is None:
    return
  inorder(nd.left)
  
  print nd.val
  
  inorder(nd.right)
  
  
if __name__ == "__main__":
  val = [0, 1, 2, None, None, 3, 4, None, None, None, None, None, None, None, 5]
  nd = nodeBuilder.deserialized(val)
  inorder(nd)