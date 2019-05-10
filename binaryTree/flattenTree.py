from treeUtil import node
from treeUtil import nodeBuilder

def flattenTreeHelper(nd, resList):
  if nd is None:
    return 
  
  resList.append(nd.val)
  flattenTreeHelper(nd.left, resList)
  flattenTreeHelper(nd.right, resList)
 

def flattenTree(nd):
  resList = []
  flattenTreeHelper(nd, resList)
  return resList
  
  
  
if __name__ == "__main__":
  val = [5, 4, 6, 3, 4.5, 5.5, 7]
  nd = nodeBuilder.deserialized(val)
  print flattenTree(nd)
  
  val = [5, 4, 6, 3, 4.5, 5.5, 7, 8]
  nd = nodeBuilder.deserialized(val)
  print flattenTree(nd)
  