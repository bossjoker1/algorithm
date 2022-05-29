# 字符串模拟

class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        v4 = queryIP.strip().split('.')
        v6 = queryIP.strip().split(':')

        if len(v4) == 4:
            for subs in v4:
                if len(subs) < 1 or (subs[0] == '0' and len(subs) > 1):
                    return 'Neither'
                for i in range(len(subs)):
                    if not (48<=ord(subs[i]) <=57):
                        return 'Neither'

                if int(subs) > 255:
                    return 'Neither'
            return 'IPv4'

        elif len(v6) == 8:
            for subs in v6:
                if len(subs) > 4  or len(subs) < 1:
                    return 'Neither'

                for i in range(len(subs)):
                    if not ( 48<=ord(subs[i])<=57 or 65<=ord(subs[i])<=70 or 97<=ord(subs[i])<=102):
                        return 'Neither'

            return 'IPv6'
        else:
            return 'Neither'
