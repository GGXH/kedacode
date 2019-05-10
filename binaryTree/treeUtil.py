
class node:
  def __init__(self, val, left = None, right= None):
    self._val = val
    self._left = left
    self._right = right
    
  @property
  def left(self):
    return self._left
    
  @property
  def right(self):
    return self._right
  
  @property
  def val(self):
    return self._val

class nodeBuilder:
  @staticmethod
  def deserialized(valArray):
    n = len(valArray)
    if n == 0:
      return None
    ndList = [None] * n
    for i in xrange(n):
      if valArray[i] is not None:
        nd = node(valArray[i])
        ndList[i] = nd
        pi = ( i - 1 ) / 2
        if pi >= 0:
          if i % 2 == 1:
            ndList[pi].left = nd
          else:
            ndList[pi].right = nd
    return ndList[0]