import gmplot

import csv

f = open('myoutput.csv')
csv_f = csv.reader(f)

temp = list(csv_f)
#print temp[0][10]
latitude2 = []
longitude2 = []


for x in temp:
	latitude2.append(float(x[10]))

for y in temp:
	longitude2.append(float(y[10]))


#print latitude2
#print longitude2
	

#for row in csv_f:
#  print row



file = open("puntoyx-test.txt", "r")
#file = open("puntoyx.txt", "r")
#	latitude = []
#	longitude = []
#	for line in file:
#	    info = line.split(" ")
#	    # check the input parameters
#	    latitude.append(float(info[1]))
#	    longitude.append(float(info[0]))
#	    
#print([latitude[0]])
#print([longitude[0]])


#gmap = gmplot.GoogleMapPlotter(37.428,-122.145, 16)
#gmap = gmplot.GoogleMapPlotter(-122.145,37.428, 16)
gmap = gmplot.GoogleMapPlotter(latitude2[0],longitude2[0],16)
#gmap.plot(latitudes, longitudes, 'cornflowerblue', edge_width=10)
#gmap.scatter(latitudes, longitudes,'#3B0B39', size=40, marker=False)
#gmap.scatter(latitudes, longitudes, 'k', marker=True)


gmap.heatmap(latitude2, longitude2,10,20,None,0.8,100,True)

gmap.draw("mymap-test4.html")