class Node:
    def __init__(self, data, next = None):
        self.data = data
        self.next = next

class LinkedList:
    def __init__(self, head = None):
        self.head = head
        
# Parameters:
#  list: LinkedList
# return type: None

def sortList(list):
    # your code here
    def mergesortedlist(lHead, rHead):
      l_cur = lHead
      r_cur = rHead
      returnedHead = None
      tail = None
      while(l_cur != None or r_cur != None):
        if(l_cur != None and r_cur != None):
          if(l_cur.data <= r_cur.data):
            lower = l_cur
            l_cur = l_cur.next
          else:
            lower = r_cur
            r_cur = r_cur.next
        elif(l_cur != None):
          lower = l_cur
          l_cur = l_cur.next
        else:
          lower = r_cur
          r_cur = r_cur.next
        if(returnedHead == None):
          returnedHead = lower
          tail = lower
        else:
          tail.next = lower
          tail = lower
      return returnedHead

    def mergesort(head):
      if(head == None or head.next == None):
        return head

      slow = head
      fast = head
      while(fast != None and fast.next != None):
        slow = slow.next
        fast = fast.next.next

      rHead= slow.next
      slow.next = None
      lHead = mergesort(head)
      rHead = mergesort(rHead)

      return mergesortedlist(lHead, rHead)

    return mergesort(list.head)
