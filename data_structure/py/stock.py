import numpy as np
import pandas as pd
import pandas_datareader.data as web
import matplotlib.pyplot as plt
gel = web.DataReader(name = '000651.SZ',data_source = 'yahoo',start = '2015-1-1')
gel.info()
print(min(gel['Close']))
# gel['Close'].plot(figsize = (8,5))
print(max(gel['Close']))

gel['Return'] = np.log(gel['Close'] / gel['Close'].shift(1))
gel[['Close','Return']].tail()
