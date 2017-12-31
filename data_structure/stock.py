import numpy as np
import pandas as pd
import pandas.io.data as web
import matplotlib.pyplot as plt
gel = web.DataReader(name = '000651.SZ',data_source = 'yahoo',start = '2015-1-1')
gel.info()
