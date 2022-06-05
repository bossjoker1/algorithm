class TextEditor:

    def __init__(self):
        self.l = 0
        self.s = ""
        self.pos = 0


    def addText(self, text: str) -> None:
        # print("add", self.s, self.pos)
        n = len(text)
        self.s = self.s[:self.pos] + text + self.s[self.pos:]
        self.pos += n
        self.l += n


    def deleteText(self, k: int) -> int:
        # print("delete", self.s, self.pos)
        self.l -= min(self.pos, k)
        if self.pos < k:
            self.s = self.s[self.pos:]
            tmp = self.pos
            self.pos = 0
            return tmp
        else:
            self.s = self.s[0:self.pos-k] + self.s[self.pos:]
            self.pos -= k
            return k
        
 
    def cursorLeft(self, k: int) -> str:
        # print("Left", self.s, self.pos)
        if k >= self.pos:
            self.pos = 0
            return ""
        else:
            self.pos -= k
            tmp = min(10, self.pos)
            return self.s[self.pos - tmp : self.pos]

    def cursorRight(self, k: int) -> str:
        # print("right", self.s, self.pos)
        self.pos = min(self.l, self.pos + k)
        tmp = min(10, self.pos)
        return self.s[self.pos - tmp : self.pos]



# Your TextEditor object will be instantiated and called as such:
# obj = TextEditor()
# obj.addText(text)
# param_2 = obj.deleteText(k)
# param_3 = obj.cursorLeft(k)
# param_4 = obj.cursorRight(k)