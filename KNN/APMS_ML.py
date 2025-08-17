import csv
import math
from googlesearch import search
A=[]
with open(r"C:\Users\Dell\OneDrive\Documents\pollutantsclassification.csv",newline="") as csvfile:
    for row in csv.reader(csvfile):
        A.append(row)
no_instances=len(A)
no_attributes=(len(A[0])-2)
D=[[0]*3 for i in range(no_instances-1)]
pollutants=[0]*8
pollutants[0]=int(input("Enter the content of PM10: "))
pollutants[1]=int(input("Enter the content of SO2: "))
pollutants[2]=int(input("Enter the content of PM2.5: "))
pollutants[3]=int(input("Enter the content of O3: "))
pollutants[4]=int(input("Enter the content of NO2: "))
pollutants[5]=int(input("Enter the content of CO: "))
pollutants[6]=int(input("Enter the content of NO: "))
pollutants[7]=int(input("Enter the content of NH3: "))
print("PM10 SO2 PM2.5 O3 NO2 CO NO NH3")
print("The pollutants content in ppm: ",pollutants)
def euclidean(A,pollutants):
    dist=0;
    for i in range(0,no_attributes):
        x=(int)(A[i])
        dist=dist+pow((x-pollutants[i]),2)
    dist=math.sqrt(dist)
    return dist
def KNN(D):
    D.sort()
    print("Enter the number of points for consideration: ")
    n=int(input())
    print("The sources of pollution are: ")
    for i in range(0,n):
        print(D[i][2])
    print("\nThe major soucre of pollution: ")
    count1=0
    count2=0
    count3=0
    count4=0
    count5=0
    count6=0
    count7=0
    if(D[i][2]=="Safe"):
        count1=count1+1
    elif(D[i][2]=="Dust from unsealed roads"):
        count2=count2+1
    elif(D[i][2]=="Power station"):
        count3=count3+1
    elif(D[i][2]=="Smoke from fires"):
        count4=count4+1
    elif(D[i][2]=="Car and truck exhausts"):
        count5=count5+1
    elif(D[i][2]=="Burning fossil fuels"):
        count6=count6+1
    else:
        count7=count7+1
    if(count1>count2 and count1>count3 and count1>count4 and count1>count5 and count1>count6 and count1>count7):
        print("Safe")
    elif(count2>count1 and count2>count3 and count2>count4 and count2>count5 and count2>count6 and count2>count7):
        print("Dust from unsealed roads")
    elif(count3>count1 and count3>count2 and count3>count4 and count3>count5 and count3>count6 and count3>count7):
        print("Power station")
        query="Power stations pollution near me"
        for i in search(query):
            print(i)
    elif(count4>count1 and count4>count2 and count4>count3 and count4>count5 and count4>count6 and count4>count7):
        print("Smoke from fires")
    elif(count5>count1 and count5>count2 and count5>count4 and count5>count6 and count5>count3 and count5>count7):
        print("Car and truck exhausts")
    elif(count6>count1 and count6>count2 and count6>count4 and count6>count5 and count6>count3 and count6>count7):
        print("Burning fossil fuels")
    else:
        print("Industry")
        query="Factory Pollution near me"
        for i in search(query):
            print(i)
            
    

for i in range(1,no_instances):
    D[i-1][0]=euclidean(A[i],pollutants)
    D[i-1][1]=A[i][no_attributes]
    D[i-1][2]=A[i][no_attributes+1]
for i in range(0,no_instances-1):
    print(D[i])
KNN(D)
    






        
