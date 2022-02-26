class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        a, b = num1.split("+"), num2.split("+")
        a1, b1 = int(a[0]), int(a[1][:-1])
        a2, b2 = int(b[0]), int(b[1][:-1])

        s = a1 * a2 + b1 * b2 * (-1)
        f = a1 * b2 + a2 * b1

        return str(s) + "+" + str(f) + "i" 