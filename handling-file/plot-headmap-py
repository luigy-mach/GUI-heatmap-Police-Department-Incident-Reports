import gmplot



file = open("puntoyx-test.txt", "r")
#file = open("puntoyx.txt", "r")
latitude = []
longitude = []
for line in file:
    info = line.split(" ")
    # check the input parameters
    latitude.append(float(info[1]))
    longitude.append(float(info[0]))
    
print([latitude[0]])
print([longitude[0]])



#gmap = gmplot.GoogleMapPlotter(37.428,-122.145, 16)
#gmap = gmplot.GoogleMapPlotter(-122.145,37.428, 16)
gmap = gmplot.GoogleMapPlotter(latitude[0],longitude[0],16)
#gmap.plot(latitudes, longitudes, 'cornflowerblue', edge_width=10)
#gmap.scatter(latitudes, longitudes,'#3B0B39', size=40, marker=False)
#gmap.scatter(latitudes, longitudes, 'k', marker=True)


gmap.heatmap(latitude, longitude,10,20,None,0.8,100,True)

gmap.draw("mymap-test4.html")