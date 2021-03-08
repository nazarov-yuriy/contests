import unittest
from typing import List


class Solution:
    def removeSubfolders(self, folders: List[str]) -> List[str]:
        root = {}
        for folder in folders:
            parts = folder.split("/")
            node = root
            for part in parts:
                node = node.setdefault(part, {})
            node["@"] = True  # terminal
        res = []
        for folder in folders:
            parts = folder.split("/")
            node = root
            removed = False
            for part in parts:
                if node.get("@"):
                    removed = True
                    break
                node = node.setdefault(part, {})
            if not removed:
                res.append(folder)
        return res


class Test(unittest.TestCase):
    def test(self):
        folders = ["/a", "/a/b", "/c/d", "/c/d/e", "/c/f"]
        out = ["/a", "/c/d", "/c/f"]
        self.assertEqual(Solution().removeSubfolders(folders), out)
        folders = ["/a","/a/b/c","/a/b/d"]
        out = ["/a"]
        self.assertEqual(Solution().removeSubfolders(folders), out)
        folders = ["/a/b/c","/a/b/ca","/a/b/d"]
        out = ["/a/b/c","/a/b/ca","/a/b/d"]
        self.assertEqual(Solution().removeSubfolders(folders), out)
