# #
# #     # sum += i
# #     # print("%d" % a[i])
# #     # if i % 5 == 0:
# #     #     print('\n')
# # # print(sum)
# # # sum = [3,2,1,'A']
# # # sum.sort()
# # # print(sum)
# # # sum = 'abdc def'
# # dic = {}
# # key = [1,2,3]
# # dic[key] = 'hello'
# # print(r"hello,\n")
# a = 1000
# def hexfun(a):
#     sum = 0
#     s = []
#     while(a):
#         b = a % 16
#         a = a // 16
#         s.append(b)
#     while(len(s)):
#         sum = sum * 10 + s.pop()
#     return sum
# b = hexfun(200)
# c = hex(200)
# print(b)
# print(c)
a = 'abc'
dir(str)
a = a.find('c')
print(a)
