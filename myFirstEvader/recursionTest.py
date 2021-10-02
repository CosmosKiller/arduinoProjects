#This is a quick test for the "evasionProtocol" function defined in "myFirstEvader" program
#It's used to test the capability of using recursion if the evader ends up in a corner or an alley

def recTest():
    leftNum = int(input("Choose your left number (0/1): "))
    rightNum = int(input("Choose your rigth number (0/1): "))

    if leftNum == 0 and rightNum == 1:
        print("Rotating right...")
    elif leftNum == 1 and rightNum == 0:
        print("Rotating left...")
    elif leftNum == 1 and rightNum == 1:
        print("I'm a thinking machine, i'll do whatever i want!!")
    else:
        print("Going backwards...")

        recTest()


def main():
    print("Welcome!")

    recTest()



if __name__ == "__main__":
    main()