# you can write to stdout for debugging purposes, e.g.
# print "this is a debug message"

def solution(N):
    sol = 0
    curr_sol = 0

    while N:
        if N & 1:
            break
        N /= 2

    while N:
        if N & 1:
            if curr_sol > sol:
                sol = curr_sol
            curr_sol = 0
        else:
            curr_sol += 1

        N /= 2

    return sol
