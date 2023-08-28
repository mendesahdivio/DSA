import Foundation



class RemoveSpecialCharactersFromString {
  func removeSpecialCharacters(_ input: String) -> String {
    do {
      let regX = try NSRegularExpression(pattern: "[^0-9a-zA-Z]+", options: .caseInsensitive)
      let range = NSRange(location: 0, length: input.utf16.count)
      let output = regX.stringByReplacingMatches(in: input, options: [], range: range, withTemplate: "")
      return output
    } catch {
      print(error.localizedDescription)
      return ""
    }
  }
}
