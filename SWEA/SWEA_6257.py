fruit = ['   apple    ', 'banana', '  melon']

answer = {key.strip(): len(key.strip()) for key in fruit}
print(answer)
