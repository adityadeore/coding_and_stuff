class Tree:
    def __init__(self, data, left = None, right = None):
        self.data = data
        self.left = left
        self.right = right
        
# Parameters:
#  root: Tree
# return type: None
'''
def flattenTree(root):
    
  def recFlattenTree(root):
    if(root == None):
      return None

    #print(root.val)
    recFlattenTree(root.left)
    recFlattenTree(root.right)
    if(root.left != None):
        rightsubtree = root.right
        root.right = root.left
        root.left = None
        temp = root
        while (temp.right != None):
            temp = temp.right
        temp.right = rightsubtree
  
  recFlattenTree(root)
'''   
def flattenTree(root):
    head = None
    def recFlattenTree(root):
      global head
      if(root == None):
        return None

      #print(root.val)
      recFlattenTree(root.right)
      recFlattenTree(root.left)
      root.left = None
      root.right = head
      head = root

    recFlattenTree(root)
   
