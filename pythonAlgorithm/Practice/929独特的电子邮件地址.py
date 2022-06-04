# 调api就行了
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        email_set = set()
        for email in emails:
            name, domain = email.split('@')
            k = name.find('+') 
            if k != -1:
                name = name[:k]
            name = name.replace('.', '')
            email_set.add(name + '@' + domain)
        # print(email_set)
        return len(email_set)