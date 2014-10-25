# Crack the coding interview
# Q 9.1

def count(n):
    memoization = {}
    def recurse(n):
        if n in memoization:
            return memoization[n]

        if n == 0:
            return 1
        elif n < 0:
            return 0

        memoization[n] = recurse(n-1) + recurse(n-2) + recurse(n-3)
        return memoization[n]
    return recurse(n)


if __name__ == '__main__':
    print count(30)
