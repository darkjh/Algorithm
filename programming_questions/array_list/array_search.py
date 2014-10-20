"""Find special number in array

Given A, an array of integers in ascending order, find any index x that
satisfied A[x] == x. Index starts from 0.
"""


def search(A, start=0):
    if len(A) == 0:
        return None
    mid = len(A) / 2
    match = mid + start
    if A[mid] == match:
        return match
    elif A[mid] < match:
        return search(A[mid+1:], mid+1)
    else:
        return search(A[:mid], start)


if __name__ == '__main__':
    assert search([-1, 1, 2, 3, 10]) in (1, 2, 3)
    assert search([10, 15, 20, 25]) == None
    assert search([-15, -1, 2, 4, 6, 100]) == 2
    assert search([0]) == 0
    assert search([]) == None
