func backspaceCompare(s string, t string) bool {
  return removeBackspaces(s) == removeBackspaces(t)
}

func removeBackspaces(s string) (t string) {
  count := 0
  for i := len(s) - 1; i >= 0; i-- {
    if s[i] == '#' {
      count++
    } else if count > 0 {
      count--
    } else {
      t += string(s[i])
    }
  }
  return t
}
