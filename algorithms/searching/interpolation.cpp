/*
Algorithm
Rest of the Interpolation algorithm is same except the above partition logic.

Step1: In a loop, calculate the value of “pos” using the probe position formula.
Step2: If it is a match, return the index of the item, and exit.
Step3: If the item is less than arr[pos], calculate the probe position of the left sub-array.
        Otherwise calculate the same in the right sub-array.
Step4: Repeat until a match is found or the sub-array reduces to zero.
*/