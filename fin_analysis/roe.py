'''
Module to calculate ROE of a company 
'''
from numerize import numerize

class Roe:
  def __init__(self, balance_sheet=None, income_statement=None, cfs=None):
    self.balance_sheet=balance_sheet
    self.income_statement = income_statement
    self.cfs = cfs
    self.roes=[]
    self.roes_raw=[]
  def get_roe(self):
    periods = self.balance_sheet.columns
    #print(self.balance_sheet)
    #print(periods)
    for i in range(0, len(periods)):
      netincome = self.income_statement[periods[i]]['netIncomeFromContinuingOps']
      #print(netincome)
      if(i < len(periods) - 1):
        avgshareequity = self.balance_sheet[periods[i]]['totalStockholderEquity'] + self.balance_sheet[periods[i+1]]['totalStockholderEquity']
        avgshareequity = avgshareequity//2
      else:
        avgshareequity = self.balance_sheet[periods[i]]['totalStockholderEquity']
      #print(avgshareequity)
      self.roes.append(numerize.numerize(float(netincome/avgshareequity),2))
      
    return self.roes
  def get_roe_raw(self):
    periods = self.balance_sheet.columns
    #print(self.balance_sheet)
    #print(periods)
    for i in range(0, len(periods)):
      netincome = self.income_statement[periods[i]]['netIncomeFromContinuingOps']
      #print(netincome)
      if(i < len(periods) - 1):
        avgshareequity = self.balance_sheet[periods[i]]['totalStockholderEquity'] + self.balance_sheet[periods[i+1]]['totalStockholderEquity']
        avgshareequity = avgshareequity//2
      else:
        avgshareequity = self.balance_sheet[periods[i]]['totalStockholderEquity']
      #print(avgshareequity)
      self.roes_raw.append(netincome/avgshareequity)

    return self.roes_raw

