n = int(input("Please enter a number: "))
sum = 0
product = 1
choice = input("Write \"sum\" for sum and \"product\" for product: ")

if choice == "sum":
    for i in range(1, n+1): 
        sum += i
        print(sum)
elif choice == "product":
    for i in range(1, n+1): 
        product *= i
        print(product)
else:
    print("That's not a choice.")