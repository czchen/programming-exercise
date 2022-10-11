package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {
	l := &ListNode{
		Val: 1,
		Next: &ListNode{
			Val: 2,
			Next: &ListNode{
				Val: 3,
				Next: &ListNode{
					Val: 4,
					Next: &ListNode{
						Val: 5,
					},
				},
			},
		},
	}

	middleNode(l)
}

func middleNode(head *ListNode) *ListNode {
	current := head
	middle := head

	for current != nil && current.Next != nil {
		current = current.Next.Next
		middle = middle.Next
	}

	return middle
}
