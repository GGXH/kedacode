from treeUtil import node
from treeUtil import nodeBuilder

def postorder(nd):
  if nd is None:
    return
  postorder(nd.left)
  postorder(nd.right)
  print nd.val
  
  
if __name__ == "__main__":
  val = [0, 1, 2, None, None, 3, 4, None, None, None, None, None, None, None, 5]
  nd = nodeBuilder.deserialized(val)
  postorder(nd)
  
  