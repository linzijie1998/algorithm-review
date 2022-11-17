package main

import "fmt"

func upperBound(target int, nums []int) int {
	if len(nums) == 0 {
		return -1
	}
	left, right := 0, len(nums)-1
	for left < right {
		middle := (left + right) / 2
		if nums[middle] <= target {
			left = middle + 1
		} else {
			right = middle
		}
	}
	if nums[left] <= target {
		return -1
	}
	return left
}

func numMatchingSubseq(s string, words []string) int {
	var pos [26][]int
	for i, v := range s {
		pos[v-'a'] = append(pos[v-'a'], i)
	}
	cnt := 0
	for _, word := range words {
		matched := true
		cur := -1
		for _, c := range word {
			idx := upperBound(cur, pos[c-'a'])
			if idx == -1 {
				matched = false
				break
			}
			cur = pos[c-'a'][idx]
		}
		if matched {
			cnt++
		}
	}
	return cnt
}

func main() {
	s := "rwpddkvbnnuglnagtvamxkqtwhqgwbqgfbvgkwyuqkdwhzudsxvjubjgloeofnpjqlkdsqvruvabjrikfwronbrdyyjnakstqjac"
	words := []string{"lnagtva", "kvbnnuglnagtvamxkqtwhqgwbqgfbvgkwyuqkdwhzudsxvju", "rwpddkvbnnugln", "gloeofnpjqlkdsqvruvabjrikfwronbrdyyj", "vbgeinupkvgmgxeaaiuiyojmoqkahwvbpwugdainxciedbdkos", "mspuhbykmmumtveoighlcgpcapzczomshiblnvhjzqjlfkpina", "rgmliajkiknongrofpugfgajedxicdhxinzjakwnifvxwlokip", "fhepktaipapyrbylskxddypwmuuxyoivcewzrdwwlrlhqwzikq", "qatithxifaaiwyszlkgoljzkkweqkjjzvymedvclfxwcezqebx"}
	fmt.Println(numMatchingSubseq(s, words))
}
