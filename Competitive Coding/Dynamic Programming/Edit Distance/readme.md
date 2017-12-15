## Edit distance
 Edit distance is a way of quantifying how dissimilar two strings (e.g., words) are to one another by counting the minimum number of operations required to transform one string into the other.

![](http://www.ideserve.co.in/learn/img/editDistance_0.gif)

 Given two strings a and b on an alphabet Σ, the edit distance d(a, b) is the minimum-weight series of edit operations that transforms a into b.
* Insertion of a single symbol. If a = uv, then inserting the symbol x produces uxv. This can also be denoted ε→x, using ε to denote the empty string.
* Deletion of a single symbol changes uxv to uv (x→ε).
* Substitution of a single symbol x for a symbol y ≠ x changes uxv to uyv (x→y).


#### Applications
*  Computational biology and natural language processing, e.g. the correction of spelling mistakes or OCR errors
*  Approximate string matching, where the objective is to find matches for short strings in many longer texts, in situations where a small number of differences is to be expected.

[More info](https://en.wikipedia.org/wiki/Edit_distance)
