package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func addNode(iter *ListNode, val int) (node *ListNode) {
	node = new(ListNode)
	node.Val = val
	node.Next = nil
	if iter != nil {
		iter.Next = node
	}
	return
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	a, b := l1.Val, l2.Val
	l1, l2 = l1.Next, l2.Next
	sum := a + b
	carry := sum / 10
	head := addNode(nil, sum%10)
	iter := head
	for !(l1 == nil && l2 == nil) {
		a = 0
		if l1 != nil {
			a = l1.Val
			l1 = l1.Next
		}
		b = 0
		if l2 != nil {
			b = l2.Val
			l2 = l2.Next
		}
		sum = a + b + carry
		iter = addNode(iter, sum%10)
		carry = sum / 10
	}
	if carry != 0 {
		addNode(iter, carry)
	}
	return head
}

func main() {

}
