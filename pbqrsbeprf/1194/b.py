from sys import stdin

q = int(stdin.readline())

for _ in range(q):
    n, m = [int(x) for x in stdin.readline().split()]
    matrix = []
    min_row = m
    min_col = n
    for i in range(n):
        matrix.append([c for c in stdin.readline().strip()])
        missing_row = sum(c != '*' for c in matrix[i])
        min_row = min(min_row, missing_row)

    candidates_row = set()
    for i in range(n):
        missing_row = sum(c != '*' for c in matrix[i])
        if min_row == missing_row:
            candidates_row.add(i)

    for j in range(m):
        missing_col = sum(matrix[i][j] != '*' for i in range(n))
        if any(matrix[i][j] != '*' and i in candidates_row for i in range(n)):
            missing_col -= 1
        min_col = min(min_col, missing_col)

    print(min_row + min_col)
