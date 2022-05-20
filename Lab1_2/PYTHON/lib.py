import time
import pickle


def getTime(str_time: str):
    res = time.strptime(str_time, "%H:%M")
    return res


def writeF(nameF):
    flag=input('Do you want to rewrite the file? (y/n)')
    while True:
        if flag=='y':
            outF=open(nameF,'wb')
            break
        elif flag=='n':
            print("----------Old file:\n")
            printInfoF(nameF)
            outF=open(nameF,'ab')
            break
        else:
            print("Incorrect input: Enter y or n \n")
    count = int(input("----------Enter how many buses you want to add: "))
    bus_list = []
    for i in range(count):
        bus = init_bus()
        bus_list.append(bus)
        print()
    for bus in bus_list:
        pickle.dump(bus, outF)
    outF.close()


def init_bus():
    bus = {
        'destination_city' : input("\nEnter destination city: "),
        'departure_time' : input('Enter the time of departure in the format <hh:mm>: '),
        'duration_trip' : input('Enter the travel time in the format <hh:mm>: ')
    }
    return bus

def printInfoF(nameF):
    bus_list = readF(nameF)
    for bus in bus_list:
        print("Destination city: ", bus['destination_city'])
        print("Departure time: ", bus['departure_time'])
        print("Duration trip: ", bus['duration_trip'])
        print()
        

def readF(nameF):
     bus_list = []
     with open(nameF, 'rb') as file:
        file.seek(0, 2)
        endF = file.tell()
        file.seek(0, 0)
        while file.tell() != endF:
            bus = pickle.load(file)
            bus_list.append(bus)
     return bus_list



def updateF(nameF):
    bus_list = readF(nameF)
    with open(nameF, 'wb') as file:
        for bus in bus_list:
            flag=True
            departure_time = getTime(bus['departure_time'])
            duration_trip = getTime(bus['duration_trip'])
            h1 = departure_time.tm_hour
            h2 = duration_trip.tm_hour
            m1 = departure_time.tm_min
            m2 = duration_trip.tm_min
            h = h1 + h2
            m = m1 + m2
            if m >= 60:
                h = h + 1
                m = m - 60
            if (h1 >= 23 or h1 < 6 or (h1 == 6 and m1 == 0)) or (h >= 23 or h < 6 or (h == 6 and m == 0)):
                if h2>=17:
                    print("The bus leaves at night, but the duration of the trip is more then 17 hours. OK")
                else:
                    print("The bus leaves at night, and the duration of the trip is less then 17 hours. NOT OK")
                    flag=False
            else:
                print("Day bus. OK")
            printInfoBus(bus)
            print()
        
            if flag:
                pickle.dump(bus, file)



def lastBus(nameF):
    needCity=input("Enter the name of city, whoose last bus you need: ")
    bus_list = readF(nameF)
    ind=-1
    needH=0
    needM=0
    i=0
    for bus in bus_list:
        if needCity==bus['destination_city']:
            departure_time = getTime(bus['departure_time'])
            h1 = departure_time.tm_hour
            m1 = departure_time.tm_min
            if h1>needH:
                needH=h1
                needM=m1
                ind=i
            elif needH==h1 and needM<m1:
                needH=h1
                needM=m1
                ind=i
            i+=1
    if ind==-1:
        print("There are no buses to this city")
    else:
        print("The last bus to ", needCity," : \n")
        printInfoBus(bus_list[ind])
def printInfoBus(bus):
    print("Destination city: ", bus['destination_city'])
    print("Departure time: ", bus['departure_time'])
    print("Duration trip: ", bus['duration_trip'])
