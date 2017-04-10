import matplotlib.pyplot as plt

from fft import fft
from numpy import array
import math
from pylab import *
from scipy import *
from scipy import optimize


plotfirst = True

if plotfirst == False : 
 
    N = 1024
    f = 10.0

    x = array([ float(i) for i in xrange(N) ] )
    y = array([ math.sin(-2*math.pi*f* xi / float(N))  for xi in x ])
   
    Y = fft(y)

    Yre = [math.sqrt(Y[i].real**2 + Y[i].imag**2) for i in xrange(N)]

    s1 = plt.subplot(2, 1, 1)
    plt.plot( x, y )

    s2 = plt.subplot(2, 1, 2)
    s2.set_autoscalex_on(False)
    plt.plot( x, Yre )
    plt.xlim([0,1024])

    plt.show()


else : 
    # data downloaded from ftp://ftp.cmdl.noaa.gov/ccg/co2/trends/co2_mm_mlo.txt
    print ' C02 Data from Mauna Loa'
    data_file_name = 'co2_mm_mlo.txt'
    file = open(data_file_name, 'r')
    lines = file.readlines()
    file.close()
    print ' read', len(lines), 'lines from', data_file_name

    yinput = []
    xinput = []

    for line in lines :
        if line[0] != '#' :
            try:
                words = line.split()
                xval = float(words[2])
                yval = float( words[5] )
                yinput.append( yval )
                xinput.append( xval )
            except ValueError :
                print 'this just is not going to cut it :`(',line

    Float = array( yinput[0:1024] ) #cut off at 256 bits
    xa = array([ float(i) for i in xrange(len(Float)) ] )
    String = fft(Float)
    fitfunc = lambda p, x: p[0]*x+p[1]#fit poly. of degree (deg) to point (x,y).
    fitfunc2 = lambda q, x: q[0]*x+q[1]**x+q[2]#fit poly. of degree (deg) to point (x,y).
    errfunc = lambda p, x, y: fitfunc(p,x) - y
    errfunc2 = lambda q, x, y: fitfunc2(q,x) - y
    q0 = [10.,1.,5.]
    p0 = [10.,100.]
    p1, A = optimize.leastsq(errfunc, p0[:], args=(xa,Float,))
    q1, A = optimize.leastsq(errfunc2, q0[:], args=(xa,Float,))
    Yre = [math.sqrt(String[i].real**2+String[i].imag**2) for i in xrange(len(String))] #Cal. the magnitude yo
    print "The rate of increase (i.e the slope) is %f " %(p1[0])
    print "The y-int is %f" %(p1[1])
    print" the value of the coefficient of the squared term in the polynomial is %f" %(q1[1])
    time = linspace(xa.min(), xa.max(), 100)
    plt.subplot(2, 1, 1)
    plt.plot( xa, Float, "b",xa,fitfunc(p1,xa) , "r-" )
    title("trend data")
    xlabel("Months")
    ylabel("CO2 ppm")

    plt.subplot(2, 1, 2)
    plt.plot( xa, Yre )
    plt.yscale('log')
    plt.show()
