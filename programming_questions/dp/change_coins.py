"""Coin change problem

If we want to make change for N cents, and we have infinite supply of each
of valued coins, how many ways can we make the change?
"""

def change_coins_wrong(coins, N):
    """Naive recursive but wrong solution

    The idea is that at the step, we choose a coin value to use, and treat
    the rest of the cents recursively. At the end, we check if we arrive
    just at 0 cents left.
    An obvious problem is duplicated solutions, there's no constraits on
    counting results [1, 2, 3] and [1, 3, 2] as 2 solutions.
    """
    def recurse(n, m):
        if n < 0:
            return 0
        if n == 0:
            return 1
        return sum([recurse(i - j) for j in coins])


def change_coins(coins, N):
    """Recursive fomulation

    The idea is similar but we need to add ordering constraint to avoid
    duplicated solution counting.
    """
    def recurse(n, m):
        if n < 0:
            return 0
        if n == 0:
            return 1
        if n > 0 and m < 0:
            return 0
        return recurse(n - coins[m], m) + recurse(n, m-1)
    return recurse(N, len(coins)-1)


if __name__ == '__main__':
    assert change_coins([2, 5, 3, 6], 10) == 5
