import gmaps
import gmaps.datasets
gmaps.configure(api_key="heatmaps-test-1531605164679") # Your Google API key

# load a Numpy array of (latitude, longitude) pairs
locations = gmaps.datasets.load_dataset("taxi_rides")

fig = gmaps.figure()
fig.add_layer(gmaps.heatmap_layer(locations))
fig