## RSA
 One of the first public-key cryptosystems and is widely used for secure data transmission. In such a cryptosystem, the encryption key is public and it is different from the decryption key which is kept secret (private). In RSA, this asymmetry is based on the practical difficulty of the factorization of the product of two large prime numbers, the **factoring problem**.

#### Designers
Ron Rivest, Adi Shamir, and Leonard Adleman

---------------

![](https://globlib4u.files.wordpress.com/2013/10/image1_e.gif)
--------------
#### Operation

A basic principle behind RSA is the observation that it is practical to find three very large positive integers e, d and n such that with modular exponentiation for all integer m (with 0 ≤ m < n):
** (m^e)^d ~ m mod n **
and that even knowing e and n or even m it can be extremely difficult to find d.

[More info](https://en.wikipedia.org/wiki/RSA_(cryptosystem))
