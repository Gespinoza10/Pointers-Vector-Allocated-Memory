# C++ working with Pointers, Vectors, Structures, and Dynamically Allocated Memory.
In this programming assignment I am resposible to build a program with pointers, vectors, structures and dynamically allocated memory. 
#### Program Flow
1. The program will read an input file named `DailySales.txt` where each line of the input file will contain the following information (there is an example of an input file below).

`Product Id` – string (7 characters max)

`Number sold` - integer (a negative value indicates the number returned).

The `Product Id` and `Number sold` are separated by a space.

2. My program reads each item of the input file and does a `linear search` on a `vector` of `ItemStruct pointers`. (`ItemStruct` is defined below).
	
If the `Product Id` is NOT found in the `vector` of `pointers`, then I `dynamically allocate` an `ItemStruct` and populate the structure’s fields with the values from the input file and insert (using vector’s `push_back` function) the `pointer` to the `dynamically allocated` `ItemStruct` into the `vector`.

If the `Product Id` is found in the `vector` of `pointers`, then I the `Number sold` from the input file to the `NumSold` in the `structure`. 

3. After reaching the end of the input file, my program will write the `Product Id’s` and the total number of `items sold` (or returned) if the total number of items sold isn’t zero to a file named `SummaryDailySales.txt`.

```
Sample Input File		
C1567B4 3
D1668Y0 998
C1567B4 -1
D1668Y0 23
M3470K1 -12
X9718Q6 83
C1567B4 -2
M3470K1 -1
A4852T2 2
``` 

```Sample Output File
Prod ID  # Sold
-------  ------
D1668Y0    1021
M3470K1     -13
X9718Q6      83
A4852T2       2
---------------
Total      1093```
