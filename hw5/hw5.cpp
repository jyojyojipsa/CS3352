// YOUR NAME: Kangmin Kim
//
// CS 3352, fall 2022
// Homework 5: Hash functions

#include <cmath>
//#include <iostream>
// Uses the division method to calculate and return the hash of the given
// key given the number of slots.
unsigned divHash(unsigned key, unsigned numSlots)
{
   // YOUR CODE HERE
   return key % numSlots;
}

// Uses the multiplication method to calculate and return the hash of the
// given key given the number of slots and a number s.  The given number of
// slots should be rounded down to the nearest power of 2 before being used.
// A = s / 2**w, where w = the number of bits in an int and 2**w means 2 to
// the w power.

// s = 2**w * A
//  3221225471 = 4294967296 * A
      // multHash(           1,                 4,          3221225471) = 2
      // multHash(           1,                 4,          3221225472) = 3
      // multHash(           2,                 4,          2654435789) = 0
      // multHash(           2,                 4,          2718281809) = 1
	  // multHash(  3092782171,               512,          2654435761) = 183
      //                     ↑                  ↑           ↑
unsigned multHash(unsigned key, unsigned numSlots, unsigned s)
{
   const unsigned w = 8u * sizeof(unsigned);   // w = 8 * 4 == 32
   unsigned altnumSlots = 1u;
   double A = s / pow(2,w); // A = s / 2^w 
   double fractPart, wholePart;
   //int count = 0;
   
   // The given number of slots should be rounded
   // down to the nearest power of 2 before being used.
   while (numSlots >= altnumSlots * 2u) // multiply 2 to altnumSlots until it goes over numSlots
   {
	   // 4        >= 1 * 2
        altnumSlots *= 2u;
	   // 2*2
		//count++; count = 1
   }
   
   fractPart = modf(key * A,&wholePart); //https://cplusplus.com/reference/cmath/modf/

   //std::cout << "A : " << A << " s : " << s << " pow(2,w) : " << pow(2,w) << '\n';
   //std::cout << "count : " << count << '\n';
   //std::cout << "wholePart : " << wholePart << "fractPart : " << fractPart;
  
   return unsigned(fractPart * altnumSlots); // return the hash of the given key given the number of slots and a number s
}
