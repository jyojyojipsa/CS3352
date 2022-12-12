// CS 3352, fall 2022
// Homework 5

#include <iostream>

using namespace std;

// Uses the division method to calculate and return the hash of the given
// key given the number of slots.
unsigned divHash(unsigned key, unsigned numSlots);

// Uses the multiplication method to calculate and return the hash of the
// given key given the number of slots and a number s.  The given number of
// slots should be rounded down to the nearest power of 2 before being used.
// A = s / 2**w, where w = the number of bits in an int and 2**w means 2 to
// the w power.
unsigned multHash(unsigned key, unsigned numSlots, unsigned s);

// Tests the divHash and multHash functions.
int main()
{
   unsigned key, numSlots, whichS;
   const unsigned s[] = {
      101u, 102u, 65535u, 65537u,
      2654435761u, 2654435769u, 2654435770u, 2654435789u,
      2718281809u,
      3037000493u, 3037000499u, 3037000500u, 3037000507u,
      3141592637u,
      3221225471u, 3221225472u, 3221225473u,
      0u // sentinel value
   };

   // Process each combination of values: key and number of slots.
   while (cin >> key >> numSlots)
   {
      // Output the hash value according to the division method.
      cout << "divHash(" << key << ", "
           << numSlots << ") = "
           << divHash(key, numSlots) << "\n";

      // Output the hash values according to the multiplication method using
      // multiple values of A = s / 2**w.
      for (whichS = 0; s[whichS] > 0; whichS += 1)
      {
         cout << "multHash(" << key << ", "
              << numSlots << ", "
              << s[whichS] << ") = "
              << multHash(key, numSlots, s[whichS]) << "\n";
      }
   }
   return 0;
}
