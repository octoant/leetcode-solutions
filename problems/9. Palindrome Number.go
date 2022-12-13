func isPalindrome(x int) bool {
  num := strconv.Itoa(x)
  for i := 0; i < len(num) / 2; i++ {
    if num[i] != num[len(num) - 1 - i] {
      return false
    }
  }
  return true
}

