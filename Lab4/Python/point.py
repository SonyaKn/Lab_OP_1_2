from abc import ABC, abstractmethod
import random
import math

class Point(ABC):
    @abstractmethod
    def GetCoordinates(self, t):
        pass
    @abstractmethod
    def GetDistance(self, x2, y2,z2):
        pass
    @abstractmethod
    def InitialCoordinates(self):
        pass
    @abstractmethod
    def FinalCoordinates(self):
        pass


class PointXYZ(Point):

    def GetX(self):
        return self.__x

    def GetX0(self):
        return self.__x0

    def GetY(self):
        return self.__y

    def GetY0(self):
        return self.__y0
    def GetZ(self):
        return self.__z

    def GetZ0(self):
        return self.__z0

    def __init__(self):
        self.__x = 0
        self.__y = 0
        self.__z = 0
        self.__x0 = round(random.uniform(-100,100),1)
        self.__y0 = round(random.uniform(-100,100),1)
        self.__z0 = round(random.uniform(-100,100),1)
       

    def GetCoordinates(self, t):
        
        a1 = round(random.uniform(-5,5),1)
        a2 = round(random.uniform(-5,5),1)
        a3 = round(random.uniform(-5,5),1)

        self.__x =round( self.__x0 + a1 * math.sin(t),2)
        self.__y = round(self.__y0 + a2 * math.cos(t),2)
        self.__z = round(self.__z0 + a3 * math.pow(t,2),2)
        return self.__x,self.__y,self.__z,

    def GetDistance(self, x2, y2,z2):
        return math.sqrt(math.pow(x2 - self.__x,2)+math.pow(y2 - self.__y,2)+math.pow(z2 - self.__z,2))

    def InitialCoordinates(self):
        print(f"Initial Coordinates(",self.__x0,',',self.__y0,',',self.__z0,')')
    def FinalCoordinates(self):
        print("Final Coordinates: (",self.__x,',',self.__y,',',self.__z,')')

class PointXY(Point):

     def GetX(self):
        return self.__x

     def GetX0(self):
        return self.__x0

     def GetY(self):
        return self.__y

     def GetY0(self):
        return self.__y0
     def GetZ(self):
        return self.__z

     def GetZ0(self):
        return self.__z0

     def __init__(self):
       
        self.__x = 0
        self.__y = 0
        self.__z = 0
        self.__x0 = round(random.uniform(-100,100),1)
        self.__y0 = round(random.uniform(-100,100),1)
        self.__z0 = round(random.uniform(-100,100),1)

     def GetCoordinates(self, t):
        a1 = round(random.uniform(-5,5),1)
        a2 = round(random.uniform(-5,5),1)
        self.__x = round(self.__x0 + a1 * math.sin(t),2)
        self.__y = round(self.__y0 + a2 * math.cos(t),2)
        self.__z=0
        return self.__x, self.__y,self.__z

     def GetDistance(self, x2, y2,z2):
        return math.sqrt(math.pow(x2 - self.__x,2)+math.pow(y2 - self.__y,2)+math.pow(z2,2))


     def InitialCoordinates(self):
        print(f"Initial Coordinates(",self.__x0,',',self.__y0,',',self.__z0,')')
     def FinalCoordinates(self):
        print("Final Coordinates: (",self.__x,',',self.__y,',',self.__z,')')
