

str = "()()"

for j in range(0, len(str) + 1):
    new = str[0:j] + '()' + str[j:]
    print(str[0:j])
    print(str[j:])
    print("new: " + new)
