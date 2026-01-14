import matplotlib.pyplot as plt
import numpy as np
import cycler

def update_rcParams(nCycler = 10, params = {}):

  paramsDefault = {
    "text.usetex": True,
    "font.family": "serif",
    "font.serif" : "Computer Modern",
    "font.size"  : 14,
    'axes.spines.right' : False,
    'axes.spines.top'   : False,
    #'axes.spines.left'  : False,
    #'axes.spines.bottom': False,
    'legend.fancybox' : False,
    'legend.edgecolor' : 'k'
  }
  paramsDefault.update(params)
  paramsDefault.update({
    'axes.prop_cycle' : cycler.cycler('color', plt.cm.jet(np.linspace(0.0, 0.91,nCycler))),
  })

  plt.rcParams.update( paramsDefault )


