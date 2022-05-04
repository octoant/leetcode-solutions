func sortArrayByParity(nums []int) []int {
  var res []int
  for _, val := range nums {
    if val % 2 == 0 {
      res = ppend(res, val)
    }
  }
  for _, val := range nums {
    if val % 2 == 1 {
      res = append(res, val)
    }
  }
  return res
}

