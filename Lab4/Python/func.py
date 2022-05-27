
def inputT():
    time = float(input("Enter t in seconds: "))
    while True:
        if time > 0:
            return time
        else:
            time = float(input("Wrong input. Try again: "))

def inputN():
    count = int(input("Enter the number of points: "))
    while True:
        if count > 0:
            return count
        else:
            count = float(input("Wrong input. Try again: "))


def outputCoordinates(array):
    for i in range(len(array)):
        array[i].InitialCoordinates()
        array[i].FinalCoordinates()
        print()



def MinD(array):
    minD = array[0].GetDistance(array[1].GetX(), array[1].GetY(), array[1].GetZ())
    for i in range(len(array)-1):
        for j in range(i+1,len(array)):
            temp = array[i].GetDistance(array[j].GetX(), array[j].GetY(), array[j].GetZ())
            if temp < minD:
                minD = temp
    return minD