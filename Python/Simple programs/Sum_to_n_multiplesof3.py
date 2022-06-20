n = int(input( "Please enter a number to start counting: " ))
sum = 0

for i in range(1, n+1): 
    if i%3 == 0 or i%5 == 0:
        sum += i
        print(sum)