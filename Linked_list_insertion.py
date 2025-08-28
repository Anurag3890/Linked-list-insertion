class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class LinkedList:
    def __init__(self):
        self.head=None

    def insert_begin(self,val):
        newnode=Node(val)
        newnode.next=self.head
        self.head=newnode

    def insert_end(self,val):
        newnode=Node(val)
        if not self.head:self.head=newnode;return
        temp=self.head
        while temp.next:temp=temp.next
        temp.next=newnode

    def insert_pos(self,val,pos):
        if pos==0: self.insert_begin(val);return
        temp=self.head
        for _ in range(pos-1):
            if not temp:return
            temp=temp.next
        if not temp:return
        newnode=Node(val)
        newnode.next=temp.next
        temp.next=newnode

    def display(self):
        temp=self.head
        while temp:print(temp.data,end=" ");temp=temp.next
        print()

ll=LinkedList()
ll.insert_end(10);ll.insert_begin(5);ll.insert_end(20);ll.insert_pos(15,2)
ll.display()
