class Tree:
    def __init__(self, data, left = None, right = None):
        self.data = data
        self.left = left
        self.right = right
        
# Parameters:
#  root: Tree
# return type: bool

def _is_balanced(root, output):
  if root is None:
    return -1
  else:
    lefth = _is_balanced(root.left, output)
    righth = _is_balanced(root.right, output) 
    if(abs(lefth-righth) > 1):
      output[0] = False
    return 1+max(lefth, righth)

