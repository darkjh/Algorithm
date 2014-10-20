def max_sum_subarray(A):
    max_ending_here = 0
    max_so_far = 0
    for x in A:
        max_ending_here = max(0, max_ending_here + x)
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far


def max_sum_subarray_memoization(A):
    memoization = {}
    def max_sum_subarray_ending(i):
        if i < 0:
            return 0
        if i not in memoization:
            memoization[i] = max(
                max_sum_subarray_ending(i - 1) + A[i],
                0
            )
        return memoization[i]

    if len(A) == 0:
        return 0
    return max([max_sum_subarray_ending(i) for i in xrange(len(A))])


max_sum_subarray = max_sum_subarray_memoization
if __name__ == '__main__':
    assert max_sum_subarray([5, -8, 7, 8, -9]) == 15
    assert max_sum_subarray([1, 5, -100, 1, 3]) == 6
    assert max_sum_subarray([]) == 0
    assert max_sum_subarray([-1, -2, -3]) == 0
