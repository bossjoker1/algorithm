def getPositive(m, p):
    if m < 0:
        if m % p == 0:
            return 0
        else:
            t = m // p * (-1)
            m = m + t *p
    return m

print(getPositive(-1666, 999))
        
    