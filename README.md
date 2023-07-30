# Star-Power
I chopped up the data.csv file to make it easier to parse, and removed a few of the useless features (mode, key, release date, speechiness)
and saved it into "refinedData.csv"
- i think the input formatting is working correctly and we can create all 65,000 song objects seamlessly. takes about 20 seconds to run
TODO:
- I think we need to create a custom hashmap for the adjacency list of songs. just hash based on song name
- figure out how to add songs to graph and add edges
- test and refine the isSimilar function. look at connectedness of graph and try different threshholds for similarity and different weights for each feature