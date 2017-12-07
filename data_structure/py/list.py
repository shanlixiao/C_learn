class index(object):
    def __init__(self,s,t,pos):
        self.s = s
        self.t = t
        self.pos = pos
    def index(self):
        i = self.pos - 1;
        while i < len(self.s):
            j = 0
            while j < len(self.t) and i < len(self.s):
                if self.s[i] == self.t[j]:
                    i = i + 1
                    j = j + 1
                #if
                else:
                    i = i - j + 1
                    j = 0
                #else
            #while
            if j >= len(self.t):
                print ("The word is at:%d" % (i - len(self.t) + 1) )

a = index("我来自西南交通      大学","大学",1)
a.index()
