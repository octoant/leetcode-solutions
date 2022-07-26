func myAtoi(s string) int {
  i := 0
  for i < len(s) && s[i] == ' ' {
    i++
  }
  if i == len(s) {
    return 0
  }
  sign := 1
  switch (s[i]) {
    case '+':
      i++
    case '-':
      sign = -1
      i++
  }
  if i < len(s) && ('0' > s[i] || s[i] > '9') {
    return 0
  }
  var num int64 = 0
  for i = i; i < len(s) && num <= (1 << 31); i++ {
    if '0' <= s[i] && s[i] <= '9' {
      num = 10 * num + int64(s[i]) - 48
    } else {
      break
    }
  }
  if sign == 1 && num > (1 << 31) - 1 {
    return (1 << 31) - 1
  }
  if sign == -1 && num > (1 << 31) {
    return -(1 << 31)
  }
  if sign == 1 {
    return int(num)
  }
  return int(-num)
}

