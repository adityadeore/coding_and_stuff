class TreeNode:
    def __init__(self, data, left = None, right = None):
        self.data = data
        self.left = left
        self.right = right

# Parameters:
#  root: Tree
# return type: void

def reverseTree(root: TreeNode):

  def recReverseTree(root):
    if(root == None):
      return None

    left = recReverseTree(root.left)
    right = recReverseTree(root.right)

    temp = root.left
    root.left = root.right
    root.right = temp

    return root


  recReverseTree(root)

