from numerize import numerize
class AssetTurnOver:
  def __init__(self, balance_sheet=None, income_statement=None, cfs=None):
    self.balance_sheet=balance_sheet
    self.income_statement = income_statement
    self.cfs = cfs
    self.atr=[]
    self.atr_raw=[]
  def get_atr(self):
    periods = self.balance_sheet.columns
    for i in range(0, len(periods)):
      if(self.income_statement[periods[i]]['totalRevenue'] == None or self.balance_sheet[periods[i]]['totalAssets'] == None):
        print("totalRevenue or totalAssets is none for ", i)
        return None
      tr = self.income_statement[periods[i]]['totalRevenue']
      ta = self.balance_sheet[periods[i]]['totalAssets']
      self.atr.append(numerize.numerize(float(tr/ta),2))

    return self.atr
  def get_atr_raw(self):
    periods = self.balance_sheet.columns
    for i in range(0, len(periods)):
      if(self.income_statement[periods[i]]['totalRevenue'] == None or self.balance_sheet[periods[i]]['totalAssets'] == None):
        print("totalRevenue or totalAssets is none for ", i)
        return None
      tr = self.income_statement[periods[i]]['totalRevenue']
      ta = self.balance_sheet[periods[i]]['totalAssets']
      self.atr_raw.append(tr/ta)

    return self.atr_raw

