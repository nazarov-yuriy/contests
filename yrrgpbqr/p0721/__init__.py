import unittest
from typing import List


class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        next_id = 0
        res = {}
        for account in accounts:
            name, *emails = account
            emails_set = set(emails)
            matched_keys = []
            for k, v in res.items():
                if len(emails_set.intersection(v)) > 0:
                    matched_keys.append(k)
            if len(matched_keys) > 0:
                res[matched_keys[0]] |= emails_set
                for k in matched_keys[1:]:
                    res[matched_keys[0]] |= res[k]
                    del res[k]
            else:
                res[(next_id, name)] = emails_set
                next_id += 1
        return [[k[1]] + list(sorted(v)) for k, v in res.items()]


class Test(unittest.TestCase):
    def test(self):
        accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"],
                    ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
        output = [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],
                  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
        self.assertEqual(Solution().accountsMerge(accounts), output)
