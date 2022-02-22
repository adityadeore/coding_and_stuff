class Node:
    def __init__(self, data, next = None):
        self.data = data
        self.next = next

class LinkedList:
    def __init__(self, head = None):
        self.head = head
        
# Parameters:
#  list1: LinkedList
#  list2: LinkedList
# return type: LinkedList

def addTwoLinkedLists(list1: LinkedList, list2: LinkedList):
  r_head =Node(-1)
  list_r = LinkedList(head)
  prev = r_head
   
  def recaddTwoLinkedLists(l1_node, l2_node, carry):
    if(l1_node == None and l2_node == None and carry == 0):
      return
    elif(l1_node and l2_node):
      digit = (l1_node.data + l2_node.data) % 10
      carry = int((l1_node.data + l2_node.data) / 10)
      r_node = Node(digit)
      prev.next = r_node
      prev= r_node
      recaddTwoLinkedLists(l1_node.next, l2_node.next, carry):
    elif(l1_node == None and l2_node != None):
      digit = (carry + l2_node.data) % 10
      carry = int((carry + l2_node.data) / 10)
      r_node = Node(digit)
      prev.next = r_node
      prev= r_node
      recaddTwoLinkedLists(None, l2_node.next, carry):
    elif(l1_node != None and l2_node == None):
      digit = (carry + l1_node.data) % 10
      carry = int((carry + l1_node.data) / 10)
      r_node = Node(digit)
      prev.next = r_node
      prev= r_node
      recaddTwoLinkedLists(l1_node.next, None, carry):
    elif(l1_node == None and l2_node == None and carry == 1):
      r_node = Node(1)
      prev.next = r_node
      prev= r_node
      recaddTwoLinkedLists(None, None, 0):

    return
  recaddTwoLinkedLists(list1.head, list2.head, 0)
  return r_head.next

