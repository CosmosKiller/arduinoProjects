#This is a quick test for the "evasionProtocol" function defined in "myFirstEvader" program
#This time, unlike what i've done in "recursionTest.py", i'm testing the feasibility of using a while loop, instead of recursion, if the evader ends up in a corner or an alley

def wallStump():
    leftNum = int(input("Choose your left number (0/1): "))
    rightNum = int(input("Choose your rigth number (0/1): "))

    while leftNum == 0 and rightNum == 0:
        print("Going backwards...")

        leftNum = int(input("Choose another left number (0/1): "))
        rightNum = int(input("Choose another rigth number (0/1): "))

    if leftNum == 0 and rightNum == 1:
        print("Rotating right...")
    elif leftNum == 1 and rightNum == 0:
        print("Rotating left...")
    elif leftNum == 1 and rightNum == 1:
        print("I'm a thinking machine, i'll do whatever i want!!")


def main():
    print("Welcome!")

    wallStump()



if __name__ == "__main__":
    main()