s1, s2 = input().split()

rs1 = s1[::-1]
rs2 = s2[::-1]

if rs1 < rs2:
    print(rs2)
else:
    print(rs1)
