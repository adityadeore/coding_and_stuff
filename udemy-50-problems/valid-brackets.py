# Parameters:
#  str: str
# return type: bool

def isValid(str):
  stack=[]
  if len(str) == 0:
    return True

  for i in range (0, len(str)):

    if str[i] == '(' or str[i] == '{' or str[i] == '[':
      stack.append(str[i])
    elif str[i] == ')':
      if(len(stack) == 0 or '(' != stack.pop()):
        return False
    elif str[i] == '}':
      if(len(stack) == 0 or '{' != stack.pop()):
        return False
    elif str[i] == ']':
      if(len(stack) == 0 or '[' != stack.pop()):
        return False
  if len(stack) != 0:
    return False

  return True

ret = isValid('{(})')

print(ret)
