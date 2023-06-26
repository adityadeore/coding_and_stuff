from ocf import Ocf
from numerize import numerize
class Accruals:
  def __init__(self, balance_sheet=None, income_statement=None, cfs=None):
    self.balance_sheet=balance_sheet
    self.income_statement = income_statement
    self.cfs = cfs
    self.accruals_raw=[]
  def get_accruals_raw(self):
    periods = self.balance_sheet.columns
    _ocf = Ocf(self.balance_sheet, self.income_statement, self.cfs)
    ocfs = _ocf.get_ocf_raw()
    if(ocfs == None):
      return None
    for i in range(0, len(periods)):
      if('totalAssets' not in self.balance_sheet[periods[i]]):
        print("Key totalAssets is none for i ", i)
        return None
      totalassets = self.balance_sheet[periods[i]]['totalAssets']
      
      temp = ocfs[i]/totalassets
      self.accruals_raw.append(temp)

    return self.accruals_raw

