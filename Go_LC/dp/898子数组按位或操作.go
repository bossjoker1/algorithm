package main

func subarrayBitwiseORs(arr []int) int {
    set := map[int]int{}
	for i, val := range arr {
		set[val] = 0
		temp := 0
		for j := i - 1; j >= 0; j-- {
			if temp|val == temp {
				break
			}
            temp |= arr[j]
			set[temp|val] = 0
		}
	}
	return len(set)
}
