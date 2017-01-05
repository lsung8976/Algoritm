sum = 0
median = 0.0
X=int(input())

array = []
for i in range(0,X):
    buff = float(input())
    array.append(buff)

for i in range(0,X):
    sum += array[i]

mean = sum / X
print(mean)

array.sort()
if X%2 :  
    median = array[X/2]
    print(median)
else:
    median = (array[X/2] + array[X/2+1]) / 2
    print(median)
print(array[0])


