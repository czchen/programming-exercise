# you can write to stdout for debugging purposes, e.g.
# print "this is a debug message"

def solution(N):
    # write your code in Python 2.7
    sol = 0
    curr_sol = 0

    while N:
        if N & 1 == 0:
            curr_sol += 1
        else:
            if curr_sol > sol:
                sol = curr_sol
            curr_sol = 0
        N /= 2
    return sol
