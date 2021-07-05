s = input()

s1 = s.split("://")
s2 = s1[1].split("/")
print("protocol: {0}".format(s1[0]))
print("host: {0}".format(s2[0]))
print("others: {0}".format(s2[1]))
