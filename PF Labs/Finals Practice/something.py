a = int(input())

add = 0
for i in range(1, a//2 +1):
    if a%i==0:
        add += i

print(add == a)
