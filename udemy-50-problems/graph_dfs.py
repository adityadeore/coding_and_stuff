from collections import deque

class Graph:
    def __init__(self, adjList = {}):
        # the adjacency list is of type Dict[int,List[int]]
        self.adjList = adjList

def dfs(graph, root):
  stack = deque()
  visited=[]
  visited.append(root)  
#  print(root)

  for elem in graph.adjList[root]:
    stack.append(elem)
  
  while(len(stack) > 0):
    node = stack.popleft()
    if(node not in visited):
      for elem in graph.adjList[node]:
        stack.append(elem)
      visited.append(node)
#      print(node)
  print(visited)      
