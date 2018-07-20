import gmplot

# declare the center of the map, and how much we want the map zoomed in
gmap = gmplot.GoogleMapPlotter(0, 0, 2)
# plot heatmap
gmap.heatmap(-122.2222, 37.5649)

# save it to html
gmap.draw("Earthquake_heatmap.html")