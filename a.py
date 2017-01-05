mealCost = 0.0
tipPercent = 0
taxPercent = 0

mealCost = int(input())
tipPercent = int(input())
taxPercent = int(input())

tip = mealCost * tipPercent / 100
tax = mealCost * taxPercent / 100
totalCost = mealCost + tip + tax


print("The totalmeal cost is " + str(round(totalCost)) + " dollars.")
