func findUnsortedSubarray(nums []int) int {
  this := make([]int, len(nums))
  copy(this, nums)

  sort.Ints(this)
  
  x :=  0
  y := -1
  for i := 0; i < len(this); i++ {
    if this[i] != nums[i] {
      x = i
      if y == -1 {
        y = i
      }
    }
  }

  if (y == -1) {
    return 0
  }

  return x - y + 1
}
 
