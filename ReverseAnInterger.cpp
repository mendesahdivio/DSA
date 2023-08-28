#include <iostream>
#include <vector>
#include <limits>


class solution {
//time complexity O(logn)
  int reverseInteger(int val) {
    //to reverse an integer in best complexity you have to create a remainder which will keep getting updated by itself multiplying with the original val and the original getting moded with 10 and finaly we divide val by 10 and update val 
    int remainder = 0;

    while(val != 0) {
      //checks if the remainder is above or below the max and min value a 32 bit integer can store in a system since it is multiplied by 10 we devide the max and min value by 10 to check the range
      if (remainder > INT32_MAX/10 || remainder < INT32_MIN/10) {
        return 0;
      }

      //in this step we move the remainder digit to the left by multiplying it by 10
      //and we get the last digit from the val by moding it with 10
      //there by we add the last digit from the val and the remainder digit moved one left
      remainder = remainder * val + val%10;

      //this removes the last digit
      val = val/10;
    }

    return remainder;
  }
};
