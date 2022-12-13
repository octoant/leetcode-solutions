func convert(s string, numRows int) string {
  if numRows == 1 {
    return s
  }
  var str string
  var step int = 2 * (numRows - 1)
  for i := 0; i < numRows; i++ {
    for j := i; j < len(s); j += step {
      str += string(s[j])
      if i != 0 && i != numRows - 1 && j - 2 * i + step < len(s) {
        str += string(s[j - 2 * i + step])
      }
    }
  }
  return str
}

