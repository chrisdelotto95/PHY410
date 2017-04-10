import math
import matplotlib.pyplot as plt
import numpy

def least_squares_fit(x, y):
    """Perform a least-squares fit to data (x,y)
    Args :
       x : x values
       y : y values
    Returns :
       a : intercept
       b : slope
       sigma : total uncertainty (sqrt(variance/(n-2)))
       sigma_a : uncertainty on a
       sigma_b : uncertainty on b
    """
    n = len(x)
    s_x  = sum(x)
    s_y  = sum(y)
    s_xx = sum(x_i**2 for x_i in x)
    s_xy = sum(x[i]*y[i] for i in range(n))
    denom = n * s_xx - s_x**2
    if abs(denom) > 0.00001 : 
        a = (s_xx * s_y - s_x * s_xy) / denom
        b = (n * s_xy - s_x * s_y) / denom
        variance = sum((y[i] - (a + b*x[i]))**2 for i in range(n))
        sigma = math.sqrt(variance/(n-2))
        sigma_a = math.sqrt(sigma**2 * s_xx / denom)
        sigma_b = math.sqrt(sigma**2 * n / denom)
        return [a, b, sigma, sigma_a, sigma_b]
    else :
        print 'error : divided by zero!'
        return None



"""Plot data for the Gutenberg-Richter Model.
Here, we plot the curve of the number of earthquakes
greater than magnitude M, for each M value.
So, we loop over the earthquakes, and store the
frequency of each magnitude. At the end of the loop,
we compute the cumulative distribution such that the
value at magnitude M will be the integral of the frequency
distribution for >= M. This is what the Gutenberg-Richter
Model predicts. 
"""


# data downloaded from http://earthquake.usgs.gov/earthquakes/search/
print ' Earthquake data: Gutenberg-Richter Model'
data_file_name = 'california_earthquakes_2010_to_2013.csv'
file = open(data_file_name, 'r')
lines = file.readlines()
file.close()
print ' read', len(lines), 'lines from', data_file_name





histogram = dict()
magvalues = []
for line in lines:
    if line[0] != 't' :
        try:
            words = line.split(',')
            [latitude,longitude,depth,mag] = [float(s) for s in words[1:5] ]
               
            magvalues.append( mag )
           
            histogram[mag] += 1
        except KeyError : 
            histogram.setdefault(mag, 1)
        except ValueError:
            print 'bad data:', line

num_events = sum(histogram[M] for M in histogram.keys())
num_bins = len(histogram)
print ' stored', num_events, 'events in', num_bins, 'bins'

M_values = sorted(histogram.keys())
dN_values = [histogram[M] for M in M_values]

log10N_values = [ math.log10(sum(dN_values[i:]))
                  for i in range(len(M_values)) ]

MThree = [ M_values[i]
           for i in range(119,len(M_values)) ]

log10Nthree =[ log10N_values[i]
           for i in range(119,len(M_values)) ]


print 'log10N_values is '
for i in range(119,len(log10N_values)) :
    print str(M_values[i]) + '  ' + str(log10N_values[i])


plt.subplot( 2, 1, 1)
plt.plot( MThree, log10Nthree, 'v')
plt.xlabel( 'Magnitude (M)' )
plt.ylabel( 'log(N)' )

plt.subplot( 2, 1, 2)
plt.hist( magvalues, bins=70, range=[3.0,10.0], log=True, bottom=0.1,cumulative=-1)
plt.xlabel( 'Magnitude (M)' )
plt.ylabel( 'N' )

fit = least_squares_fit(MThree, log10Nthree)
print ' least_squares fit to data:'
print ' slope b = {0:6.3f} +- {1:6.3f}'.format( fit[1], fit[4])
print ' intercept a = {0:6.3f} +- {1:6.3f}'.format( fit[0], fit[3])
print ' log_10(N) error bar = {0:6.3f}'.format( fit[2] )

plt.show()
