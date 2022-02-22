class Tree:
    def __init__(self, data, left = None, right = None):
        self.data = data
        self.left = left
        self.right = right
        
# Parameters:
#  root: Tree
#  num: int
# return type: Tree

def getMinNode(root):
  if(root.left == None):
    return root
  else:
    getMinNode(root.left)

def deleteNodeBst(root, num):

  if(root is None):
    return None
  elif num < root.data:
    root.left = deleteNodeBst(root.left, num)
  elif num > root.data:
    root.right = delteNodeBst(root.right, num)
  else:
    if(root.left == None):
      return root.right
    elif root.right is None:
      return root.left
    else:
      successor = getMinNode(root.right)
      root.data = successor.data
      root.right = deleteNodeBst(root.right, sucessor.data)
    return root


