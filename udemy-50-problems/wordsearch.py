# Parameters:
#  board: List[List[char]]
#  word: str
# return type: bool

def exist(board, word):
  def clearvisited(visited):
    numrows= len(board)
    numcols = len(board[0])

    for i in range(0, numrows):
      for j in range(0, numcols) :
        visited[i][j] = 0

  def isValid(row, col, visited):
    numrows= len(board)
    numcols = len(board[0])
    if(row >= 0 and row < numrows and col >= 0 and col < numcols and visited[row][col] == 0):
      return True
    else:
      return False

  def recExist(board, row, col, visited, index, word):
    if(index == len(word)):
      return True

    else:
      ret1 = False
      ret2 = False
      ret3 = False
      ret4 = False
      if(isValid(row+1, col,visited) and board[row+1][col] == word[index]):
        visited[row+1][col] = 1
        ret1 = recExist(board, row+1, col, visited, index+1, word)
      if(isValid(row-1, col,visited) and board[row-1][col] == word[index]):
        visited[row-1][col] = 1
        ret2 = recExist(board, row-1, col, visited, index+1, word)
      if(isValid(row, col+1,visited) and board[row][col+1] == word[index]):
        visited[row][col+1] = 1
        ret3 =  recExist(board, row, col+1, visited, index+1, word)
      if(isValid(row, col-1,visited) and board[row][col-1] == word[index]):
        visited[row][col-1] = 1
        ret4 =  recExist(board, row, col-1, visited, index+1, word)
      if(ret1 or ret2 or ret3 or ret4):
        return True
      else:
        return False

  visited = []
  for i in range(0, len(board)) :
    visited.append([])
    for j in range(0, len(board[0])) :
      visited[i].append(0)

  for i in range(0, len(board)) :
    for j in range(0, len(board[0])) :
      if(board[i][j] == word[0]):
        clearvisited(visited)
        visited[i][j] = 1
        ret = recExist(board, i, j, visited, 1, word)
        if(ret == True):
          return True

  return False
board = [['K','I','N','T'],['B','I','N','S'],['G','N','Y','I'],['U','O','E','D'],['D','I','B','V'],['H','I','R','T']]

print(exist(board,"CODE")) 

