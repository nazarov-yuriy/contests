from sys import stdin

sequence = stdin.readline().strip()
best_expansions = {}
complimentary = {
    '(': ')',
    '[': ']',
    ']': '[',
    ')': '(',
}


# including start, excluding end
def best_expansion(start, end):
    if start == end:
        return ''
    if (start, end) in best_expansions:
        return best_expansions[(start, end)]

    best_candidate = None

    if (sequence[start] == '(' and sequence[end - 1] == ')') or (sequence[start] == '[' and sequence[end - 1] == ']'):
        candidate = sequence[start] + best_expansion(start + 1, end - 1) + sequence[end - 1]
        if not best_candidate or len(candidate) < len(best_candidate):
            best_candidate = candidate

    if sequence[start] == '(' or sequence[start] == '[':
        candidate = sequence[start] + complimentary[sequence[start]] + best_expansion(start + 1, end)
        if not best_candidate or len(candidate) < len(best_candidate):
            best_candidate = candidate

    if sequence[end - 1] == ')' or sequence[end - 1] == ']':
        candidate = best_expansion(start, end - 1) + complimentary[sequence[end - 1]] + sequence[end - 1]
        if not best_candidate or len(candidate) < len(best_candidate):
            best_candidate = candidate

    for middle in range(start + 1, end):
        candidate = best_expansion(start, middle) + best_expansion(middle, end)
        if not best_candidate or len(candidate) < len(best_candidate):
            best_candidate = candidate

    best_expansions[(start, end)] = best_candidate
    return best_expansions[(start, end)]


print(best_expansion(0, len(sequence)))
