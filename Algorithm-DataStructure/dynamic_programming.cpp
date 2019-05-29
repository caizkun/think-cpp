// summary for Dynamic Programming (DP)

// dp is used to optimize time complexity

// common problems
1. ask for max or min values
2. ask whether a solution is feasible
3. ask num of solutions

// less likely a dp problem
1. ask for concrete solutions inteads of num of solutions
2. the input is  a set instead of a sequence
3. the time complexity of brute-force solution is already in polynomial time


// DP 
1. Consider the last step
2. Reduce to child problem (transfer relation)
3.1 Set initial condition and solve bottom-up 
3.2 Set stopping criteria and use top-down recursion and memorization


// common meaning of dp
dp[i] -> the num of solutions ended with index i (i must be in the solution)
      -> the num of solutions for the first i elements

dp[i][j] -> the num of solutions from index i to index j (inclusive)



1. Coordinate-type DP
dp[x] -> num of ways to coordinate x
dp[x][y] -> num of ways to coordinate (x, y)

e.g., minimum path sum, unique paths I, II


2. Single-sequence-type DP
dp[i] -> the num of solutions for the firt i elements
// allocate n+1 elements, initialize dp[0] (and maybe dp[1]), dp[n] is the answer
e.g. word break, palindrome partition II

dp[i][j] -> the num of solutions between index i and index j (inclusive)
// allocate n*n elements, initialize dp[i][i], dp[i][i+1], loop in terms of len and start index, 
// dp[0][n-1] is the answer
e.g. Longest Palindrome Substring


3. Double-sequence-type DP
dp[i][j] -> num of solutions for the first i elements of seq1 and the first j elements of seq2
// allocate (n+1)*(m+1) elements, initialize dp[0][0], dp[i][0], dp[0][j], dp[n][m] is the answer
e.g. edit distance, longest common subsequence




