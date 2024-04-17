/*
1) 
Prove by induction: 2n + 3 <= 2^n when n is a positive integer and n >= 4.
Base case: n = 4
    2*4 + 3 <= 2^4
    = 11 <= 16
Therefore, when n = 4, 2n + 3 <= 2^n is true.

Inductive step:
    Suppose 2k + 3 <= 2^k where k is a positive integer and k >= 4. We will prove 2(k + 1) + 3 <= 2^(k + 1)

    2(k + 1) + 3
    = (2k + 3) + 2
    <= 2^k + 2          By inductive hypothesis
    <= 2^k + 2^k        Since k >= 4 so 2^k >= 2
    = 2 * 2^k
    = 2^(k + 1)

    Therefore, for positive integer k, if 2k + 3 <= 2^k then 2(k + 1) + 3 <= 2^(k + 1)

2)
a) P(10, 4): For the 1st character, there are 10 possible digits. For the 2nd character, there are 9
                since the first character cannot repeat and so on. Therefore, there are
                10*9*8*7 or P(10, 4) possible strings.
b) 4^6: For each question, there are (3 + 1) possibilities since there are 3 answer choices and the
        student can leave it blank. Therefore, there are 4^6 ways the student can answer the 6 question test.

3)
a) C(7, 3)/C(14, 3): There are C(7, 3) ways to choose 3 members out of the 7 women and 
                    there are C(14, 3) ways to choose 3 members out of the 14 people in the room.
                    Therefore, the probability of only women chosen is C(7, 3)/C(14, 3).

b)  P(heads >= 7) = P(heads = 7) + P(heads = 8)
    Since the outcome for each flip is either head or tails, this is a binomial distribution so
        P(heads = 7) 
            = C(8, 7) * (3/5)^7 * (2/5)^1 
            = 8 * (3/5)^7 * (2/5)
        P(heads = 8)
            = C(8, 8) * (3/5)^8 * (2/5)^0
            = (3/5)^8
    Therefore P(heads >= 7) = 8 * (3/5)^7 * (2/5) + (3/8)^8

4) 
Function1: 
    The nested for loops is theta(n) since 1 + 2 + 4 + ... + n is theta(n).
    The while loop with the nested for loop is also theta(n) since 1 + 3 + 9 + ... + n is also theta(n).
    Therefore, theta(n) + theta(n) = theta(n) so Function1 is theta(n).

Function2:
    The first for loop is theta(n)
    The second for loop is theta(log2(n)^2) since 1 + 2 + 3 + ... + log2(n) is theta([log2(n)]^2)
    Therefore, theta(n) + theta([log2(n)]^2) = theta(n) so Function2 is theta(n).
*/