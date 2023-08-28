class Solution {
  func reverseAnInteger(val: Int) ->Int {
    var remainder: Int = 0
    var mutableOriginal = val
    while(mutableOriginal != 0) {
      if (remainder > Int32.max/10 || remainder < Int32.min/10) {
        return 0
      }
      remainder = remainder*10 + mutableOriginal%10
      mutableOriginal = mutableOriginal/10
    }
    return remainder
  }
}
