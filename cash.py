from cs50 import get_float
from math import floor

def main():
    while True:
        dollars_owed = get_float ("change owed: ")
        cents_owed = floor (dollars_owed * 100)
        
        if cents_owed > 0:
            break
    
    quaters = cents_owed // 25
    dimes = (cents_owed % 25) // 10
    nickels = ((cents_owed % 25) % 10) // 5
    pennies = ((cents_owed % 25) % 10) % 5
    
    print (f"{quaters + dimes + nickels + pennies}")
    
    if __name__ == "__main__":
        main()