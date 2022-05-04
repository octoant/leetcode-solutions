func maxOperations(nums []int, k int) int {
  sort.Ints(nums)
  i, j := 0, len(nums) - 1
  n := 0
  for i < j {
    sum := nums[i] + nums[j]
    if sum < k {
      i += 1
      continue
    }
    if sum > k {
      j -= 1
      continue
    }
    i += 1
    j -= 1
    n += 1
  }
  return n
}
