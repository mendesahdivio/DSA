import Foundation

class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        if (s.count == 1) {
            return 1;
        }
        var longestSubString = 0
        var left = 0
        

        var hasSeenChar: [Character: Int] = [:]

       for right in 0...s.count - 1  {
           let charIndex = s.index(s.startIndex, offsetBy: right)
           let charater = s[charIndex]
           let previouslySeen = (hasSeenChar.keys.contains(charater) == true) ? hasSeenChar[charater] : -1
           if (previouslySeen! >= left) {
               left = previouslySeen! + 1
           }

           hasSeenChar[charater] = right;

           longestSubString = max(longestSubString, right - left + 1)
       }

       return longestSubString
    }


  func findTheLongestSubString(_ s: String)->Int {
    if (s.count < 1) {
      return 0
    }

    if (s.count == 1) {
      return 1
    }

    var longestSubString = 0

    //intialise a charcterhArray

    var charArry = [Character]()

    for char in s {
      
      if let index = charArry.firstIndex(of: char) {
        charArry.removeSubrange(0...index)
      }

      charArry.append(char)

      longestSubString = max(longestSubString, charArry.count)
      
    }

    return longestSubString
  }
}
