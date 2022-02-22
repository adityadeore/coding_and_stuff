class Tree:
    def __init__(self, data, left = None, right = None):
        self.data = data
        self.left = left
        self.right = right
        
# Parameters:
#  root: Tree
# return type: bool


def isBST(root):
  res = []
  def recisBST(root):
    nonlocal res
    if(root == None):
      return

    recisBST(root.left)
    res.append(root.data)
    recisBST(root.right)


  recisBST(root):
  for i in range(1,len(res)):
    if(arr[i] <= arr[i-1]):
      return False

  return True


