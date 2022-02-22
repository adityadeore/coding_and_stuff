class Tree:
    def __init__(self, data, left = None, right = None):
        self.data = data
        self.left = left
        self.right = right
        
# Parameters:
#  root: Tree
#  num1: int
#  num2: int
# return type: Tree

def lowestCommonAncestor(root, num1, num2):
    lca = None
    def recLowestCommonAncestor(root):
      global lca
      if(root == None or lca != None):
        return
      left = 0
      right = 0
      left = recLowestCommonAncestor(root.left)
      right = recLowestCommonAncestor(root.right)
      sum = left + right + (root.data == num1) + (root.data == num2)
      if(lca == None and sum == 2):
        lca= root
      return (sum)
      
lowestCommonAncestor(root)
