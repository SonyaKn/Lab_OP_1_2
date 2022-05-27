from func import *
from point import *


t = inputT()
k = inputN()
arrXYZ = []
for i in range(k):
    arrXYZ.append(PointXYZ())
    arrXYZ[i].GetCoordinates(t)
print("\nCoordinates of arrXYZ: ")
outputCoordinates(arrXYZ)
print()
n = inputN()
arrXY = []
for i in range(n):
    arrXY.append(PointXY())
    arrXY[i].GetCoordinates(t)
print()
print("\nCoordinates of arrXY: ")
outputCoordinates(arrXY)

minDXYZ= MinD(arrXYZ)
print(f"\nMin distance in arrXYZ is {round(minDXYZ, 3)}")

minDXY= MinD(arrXY)
print(f"\nMin distance in arrXY is {round(minDXY, 3)}")
