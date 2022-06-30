# hash md5映射
import hashlib
class Codec:
    def __init__(self):
        self.map = {}

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        _md5 = hashlib.md5()
        _md5.update(longUrl.encode("utf-8"))
        res = _md5.hexdigest()
        self.map[res] = longUrl
        return f"http://tinyurl.com/{res}"
        

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        return self.map[shortUrl.split("/")[-1]]
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
