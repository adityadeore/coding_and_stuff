from roe import Roe
from roa import Roa
from statements import Statements
from fcf import Fcf
from ocf import Ocf
from numerize import numerize
from accruals import Accruals
from leverage import Leverage
from curratio import CurrentRatio
from commonstock import CommonStock
from grossmargin import GrossMargin
from atr import AssetTurnOver
import yahoo_fin.stock_info as yf

#
tickers = yf.tickers_sp500()
#print(tickers)
#tickers = ['PVH', 'PWR', 'PXD', 'PYPL', 'QCOM', 'QRVO', 'RCL', 'RE', 'REG', 'REGN', 'RF', 'RHI', 'RJF', 'RL', 'RMD', 'ROK', 'ROL', 'ROP', 'ROST', 'RSG', 'RTX', 'SBAC', 'SBNY', 'SBUX', 'SCHW', 'SEDG', 'SEE', 'SHW', 'SIVB', 'SJM', 'SLB', 'SNA', 'SNPS', 'SO', 'SPG', 'SPGI', 'SRE', 'STE', 'STT', 'STX', 'STZ', 'SWK', 'SWKS', 'SYF', 'SYK', 'SYY', 'T', 'TAP', 'TDG', 'TDY', 'TECH', 'TEL', 'TER', 'TFC', 'TFX', 'TGT', 'TJX', 'TMO', 'TMUS', 'TPR', 'TRMB', 'TROW', 'TRV', 'TSCO', 'TSLA', 'TSN', 'TT', 'TTWO', 'TWTR', 'TXN', 'TXT', 'TYL', 'UA', 'UAA', 'UAL', 'UDR', 'UHS', 'ULTA', 'UNH', 'UNP', 'UPS', 'URI', 'USB', 'V', 'VFC', 'VLO', 'VMC', 'VNO', 'VRSK', 'VRSN', 'VRTX', 'VTR', 'VTRS', 'VZ', 'WAB', 'WAT', 'WBA', 'WBD', 'WDC', 'WEC', 'WELL', 'WFC', 'WHR', 'WM', 'WMB', 'WMT', 'WRB', 'WRK', 'WST', 'WTW', 'WY', 'WYNN', 'XEL', 'XOM', 'XRAY', 'XYL', 'YUM', 'ZBH', 'ZBRA', 'ZION', 'ZTS']
prevticker = None
for ticker in tickers:
  if(prevticker == 'FCX' or prevticker == 'GOOGL' or prevticker == 'PVH'):
    prevticker = None
    continue
  _statement = Statements(ticker, True)
  balance_sheet, income_statement, cfs = _statement.get_statements()
  _roe = Roe(balance_sheet, income_statement, cfs)
  _roa = Roa(balance_sheet, income_statement, cfs)
  _fcf = Fcf(balance_sheet, income_statement, cfs)
  _ocf = Ocf(balance_sheet, income_statement, cfs)
  _accruals = Accruals(balance_sheet, income_statement, cfs)
  _leverage = Leverage(balance_sheet, income_statement, cfs)
  _cr = CurrentRatio(balance_sheet, income_statement, cfs)
  _cs = CommonStock(balance_sheet, income_statement, cfs)
  _gm = GrossMargin(balance_sheet, income_statement, cfs)
  _atr = AssetTurnOver(balance_sheet, income_statement, cfs)
  #roes = _roe.get_roe_raw()
  #if(roes == None):
  #  continue
  roas = _roa.get_roa_raw()
  if(roas == None):
    continue
#fcfs = _fcf.get_fcf_sales_revenue()
#fcfs1 = _fcf.fcf_operating()
  #fcfs_np= _fcf.fcf_net_profits()
  #if(fcfs_np == None):
  #  continue
  ocfs = _ocf.get_ocf_raw()
  if(ocfs == None):
    continue
  accr = _accruals.get_accruals_raw()
  if(accr == None):
    continue
  lev = _leverage.get_leverage_raw()
  if(lev == None):
    continue
  cr = _cr.get_cr_raw()
  if(cr == None):
    continue
  cs = _cs.get_cs_raw()
  if(cs == None):
    continue
  gm = _gm.get_gm_raw()
  if(gm == None):
    continue
  atr= _atr.get_atr_raw()
  if(atr == None):
    continue
  avg_roa = sum(roas)/len(roas)
  #avg_roe = sum(roes)/len(roes)
#print(numerize.numerize(float(avg_roa),2))
#print(numerize.numerize(float(avg_roe),2))
#print(fcfs)
#print(fcfs1)

#print("atr\n")
##for x  in atr:
#  print(numerize.numerize(float(x),2))

#print('Atr = ', atr)
## F score
  Fscore = 0
  if(roas[0] > 0):
    Fscore += 1
  if(ocfs[0] > 0):
    Fscore += 1
  if(roas[0] > roas[1]):
    Fscore += 1
  if(accr[0] > 0):
    Fscore += 1
  if(lev[0]  < lev[1]):
    Fscore += 1
  if(cr[0] < cr[1]):
    Fscore = 1
  if (cs[0] <= cs[1]):
    Fscore += 1
  if(gm[0] > gm[1]):
    Fscore += 1
  if(atr[0] > atr[1]):
    Fscore += 1

  print('Ticker=', ticker, 'Fscore=',Fscore)
  prevticker = ticker

