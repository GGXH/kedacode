from treeUtil import node
from treeUtil import nodeBuilder


def preorder(nd):
  if nd is None:
    return
  print nd.val  
  preorder(nd.left)
  preorder(nd.right)
  

if __name__ == "__main__":
  val = [0, 1, 2, None, None, 3, 4, None, None, None, None, None, None, None, 5]
  nd = nodeBuilder.deserialized(val)
  preorder(nd)