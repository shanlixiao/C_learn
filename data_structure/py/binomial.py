import numpy as np
class binomial_tree(object):
    def __init__(self,S0,u,d,K,r,T):
        self.S0 = S0
        self.u = u
        self.d = d
        self.K = K
        self.r = r
        self.T = T
        self.su = u * S0
        self.sd = d * S0
        self.discount = np.exp(-self.r * self.T)
        self.fu = (self.su - K) if(self.su - K > 0) else 0
        self.fd = (self.sd - K) if(self.sd - K > 0) else 0
        self.q = (1/self.discount - self.d)/(self.u - self.d)
    def delta(self):
        return (self.fu - self.fd)/(S0 * u - S0 * d)
    def up_probability(self):
        return self.q
    def call_option_value(self):
        f0 = self.discount * (self.q * self.fu + (1 - self.q) * self.fd)
        return f0

ex = binomial_tree(20,1.21,0.81,21,0.12,0.5)
print(ex.u,ex.d,ex.q,ex.fu,ex.fd)
print(ex.call_option_value())
