from numerize import numerize
class CurrentRatio:
  def __init__(self, balance_sheet=None, income_statement=None, cfs=None):
    self.balance_sheet=balance_sheet
    self.income_statement = income_statement
    self.cfs = cfs
    self.cr=[]
    self.cr_raw=[]

  def get_cr(self):
    periods = self.balance_sheet.columns
    for i in range(0, len(periods)):
      if(self.balance_sheet[periods[i]]['totalCurrentAssets'] == None or self.balance_sheet[periods[i]]['totalCurrentLiabilities'] == None):
        print("totalCurrentAssets or totalCurrentLiabilities not found in ", i)
        return None
      ca = self.balance_sheet[periods[i]]['totalCurrentAssets']
      cl = self.balance_sheet[periods[i]]['totalCurrentLiabilities']
      self.cr.append(numerize.numerize(float(ca/cl),2))

    return self.cr

  def get_cr_raw(self):
    periods = self.balance_sheet.columns
    for i in range(0, len(periods)):
      if(self.balance_sheet[periods[i]]['totalCurrentAssets'] == None or self.balance_sheet[periods[i]]['totalCurrentLiabilities'] == None):
        print("totalCurrentAssets or totalCurrentLiabilities not found in ", i)
        return None
      ca = self.balance_sheet[periods[i]]['totalCurrentAssets']
      cl = self.balance_sheet[periods[i]]['totalCurrentLiabilities']
      self.cr_raw.append(ca/cl)

    return self.cr_raw

