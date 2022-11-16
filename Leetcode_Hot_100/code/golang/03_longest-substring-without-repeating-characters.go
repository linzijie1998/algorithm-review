package main

func lengthOfLongestSubstring(s string) int {
	left, right, maxLength := 0, 0, 0
	flag := [128]bool{}
	for right < len(s) {
		if !flag[s[right]] {
			flag[s[right]] = true
			right++
		} else {
			if maxLength < (right - left) {
				maxLength = right - left
			}
			if s[left] != s[right] {
				flag[s[left]] = false
				left++
			} else {
				right++
				left++
			}
		}
	}
	if maxLength < (right - left) {
		return right - left
	} else {
		return maxLength
	}
}

func main() {

}
