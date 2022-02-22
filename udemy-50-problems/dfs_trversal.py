class TreeNode:
  def __init__(self, data, left = None, right = None):
    self.data = data
    self.left = left
    self.right = right


def dfsPreorder(root:TreeNode):
  if (root == None):
    return None

  print(root.data)
  dfsPreorder(root.left)
  dfsPreorder(root.right)

def dfsInorder(root:TreeNode):
  if (root == None):
    return None
  
  dfsInorder(root.left)
  print(root.data)
  dfsInorder(root.right)

def dfsPostorder(root:TreeNode):
  if (root == None):
    return None

  dfsPostorder(root.left)
  dfsPostorder(root.right)
  print(root.data)
