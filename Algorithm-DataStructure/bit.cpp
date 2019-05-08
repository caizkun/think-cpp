// summary for bit manipulation

// and &, or |, Xor ^, not ~
// arithmetic left shift <<, right shift >>


// XOR
// 0 ^ 1 = 1
// 0 ^ 0 = 0
// 1 ^ 1 = 0

// a ^ 0 = a
// a ^ b ^ c The order does not matter!


// shift
// x >> 1 means x/2
// x << 1 means x*2

// The two's complement (补码) for a N-bit number K (1bit for sign, 0 positive, 1 negative)
// For a positive number, it is itself
// For a negative number,
// method 1: sign 1 and ( 2^(N-1) - |K| )
// method 2: sign 1 and ( invert the bits of |K| and add 1 )


// get bit
