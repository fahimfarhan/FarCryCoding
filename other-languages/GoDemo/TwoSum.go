// package main1

// import (
// 	"fmt"
// )

// func twoSum(nums []int, target int) []int {
// 	var mp = make(map[int]int)
// 	for i := 0; i < len(nums); i++ {
// 		mp[nums[i]] = i
// 	}

// 	var a int = 0
// 	var b int = 0

// 	for i := 0; i < len(nums); i++ {
// 		a = i
// 		var otherNumber int = target - nums[i]
// 		b = mp[otherNumber]
// 		// fmt.Println("" + a + " " + b)
// 		fmt.Printf("%d %d\n", &a, &b)
// 	}
// 	return nums
// }

// func main() {
// 	var n int
// 	var m int
// 	var target int = 0
// 	var nums []int

// 	fmt.Scanf("%d", &n)

// 	for i := 0; i < n; i++ {
// 		fmt.Scanf("%d", &m)
// 		nums = append(nums, m)
// 	}
// 	fmt.Scanf("%d", &target)

// 	for i := 0; i < n; i++ {
// 		fmt.Printf("%d ", nums[i])
// 		// nums = append(nums, m);
// 	}
// 	fmt.Println("")
// 	fmt.Printf("%d\n", &target)

// 	twoSum(nums, target)

// }
