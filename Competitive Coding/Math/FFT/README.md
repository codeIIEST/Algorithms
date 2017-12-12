Given two polynomial A(x) and B(x), find the product C(x) = A(x)*B(x).

A coefficient representation of a polynomial Ax is a = a0, a1, …, an-1.
• Example-
A(x) = 6x^3 + 7x^2 - 10x + 9
B(x) = -2x^3 + 4x - 5
	Coefficient representation of A(x) = (9, -10, 7, 6)
	Coefficient representation of B(x) = (-5, 4, 0, -2)

Input :
 A[] = {9, -10, 7, 6}
  B[] = {-5, 4, 0, -2}
Output : 
 -12x^6 - 14x^5 + 44x^4 - 20x^3 -75x^2 + 86x - 45 

We can do better, if we represent the polynomial in another form.
yes

Idea is to represent polynomial in point-value form and then compute the product. A point-value representation of a polynomial A(x) of degree-bound n is a set of n point-value pairs is{ (x0, y0), (x1, y1), …, (xn-1, yn-1)} such that all of the xi are distinct and yi = A(xi) for i = 0, 1, …, n-1.


