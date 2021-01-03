import unittest


class Solution:
    def digitToWord(self, digit):
        return {
            0: "Zero",
            1: "One",
            2: "Two",
            3: "Three",
            4: "Four",
            5: "Five",
            6: "Six",
            7: "Seven",
            8: "Eight",
            9: "Nine",
        }[digit]

    def tensToWords(self, num):
        if num <= 9:
            return self.digitToWord(num)
        elif num <= 19:
            return {
                10: "Ten",
                11: "Eleven",
                12: "Twelve",
                13: "Thirteen",
                14: "Fourteen",
                15: "Fifteen",
                16: "Sixteen",
                17: "Seventeen",
                18: "Eighteen",
                19: "Nineteen",
            }[num]
        else:
            tens = num // 10
            ones = num % 10
            return {
                2: "Twenty",
                3: "Thirty",
                4: "Forty",
                5: "Fifty",
                6: "Sixty",
                7: "Seventy",
                8: "Eighty",
                9: "Ninety",
            }[tens] + ((" " + self.digitToWord(ones)) if ones > 0 else "")

    def hundredsToWords(self, num):
        hundreds = num // 100
        tens_ones = num % 100
        if hundreds > 0:
            return self.digitToWord(hundreds) + " Hundred" + ((" " + self.tensToWords(tens_ones)) if tens_ones > 0 else "")
        else:
            return self.tensToWords(tens_ones)

    def numberToWords(self, num: int) -> str:
        billions = (num % int(1e12)) // int(1e9)
        millions = (num % int(1e9)) // int(1e6)
        thousands = (num % int(1e6)) // int(1e3)
        ones = (num % int(1e3)) // int(1e0)
        res = []
        if billions > 0:
            res.append(self.hundredsToWords(billions) + " Billion")
        if millions > 0:
            res.append(self.hundredsToWords(millions) + " Million")
        if thousands > 0:
            res.append(self.hundredsToWords(thousands) + " Thousand")
        if ones > 0:
            res.append(self.hundredsToWords(ones))
        return " ".join(res) or "Zero"


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(
            Solution().numberToWords(0), "Zero"
        )
        self.assertEqual(
            Solution().numberToWords(123), "One Hundred Twenty Three"
        )
        self.assertEqual(
            Solution().numberToWords(12345), "Twelve Thousand Three Hundred Forty Five"
        )
        self.assertEqual(
            Solution().numberToWords(1234567), "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
        )
        self.assertEqual(
            Solution().numberToWords(1234567891), "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
        )
        self.assertEqual(
            Solution().numberToWords(1234567890), "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety"
        )
