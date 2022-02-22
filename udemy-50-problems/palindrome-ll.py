class Node:
    def __init__(self, data, next = None):
        self.data = data
        self.next = next

class LinkedList:
    def __init__(self, head = None):
        self.head = head
        
# Parameters:
#  list: LinkedList
# return type: bool

def isPalindromeList(list):
    def checkforpalidrome(head1, head2):
      cur1 = head1
      cur2 = head2

      while(cur2 != None):
        if(cur1.data != cur2.data):
          return False
        else:
          cur1 = cur1.next
          cur2 = cur2.next
      return True

    def reverseList(head: Node):
      prev = None
      current = head
      while(current != None):
        temp = current->next
        current->next = prev
        prev = current
        current = temp

      return prev


    if (list.head == None or list.head.next == None):
      return True

    #count the nodes
    count = 0
    current = list.head
    while(current != None):
      count += 1
      current = current.next

    current = list.head
    slow = current
    fast = current

    if(count % 2 == 0):
      # even
      loop_till = count / 2
    else:
      loop_till = (count // 2) + 1
    cur_loop = 0
    seclist_head = current = list.head

    while(cur_loop < loop_till):
      seclist_head = seclist_head.next
      cur_loop += 1

    reversed_head = reverseList(seclist_head)

    return checkforpalidrome(list.head, reversed_head)

