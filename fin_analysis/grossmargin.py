from numerize import numerize
class GrossMargin:
  def __init__(self, balance_sheet=None, income_statement=None, cfs=None):
    self.balance_sheet=balance_sheet
    self.income_statement = income_statement
    self.cfs = cfs
    self.gm=[]
    self.gm_raw=[]

  def get_gm(self):
    periods = self.balance_sheet.columns
    for i in range(0, len(periods)):
      if (self.income_statement[periods[i]]['totalRevenue'] == None or self.income_statement[periods[i]]['costOfRevenue'] == None):
        print("totalRevenue or costOfRevenue is Nonr for ", i)
        return None
      tr = self.income_statement[periods[i]]['totalRevenue']
      cr = self.income_statement[periods[i]]['costOfRevenue']
      self.gm.append(numerize.numerize(float((tr-cr)/tr),2))

    return self.gm

  def get_gm_raw(self):
    periods = self.balance_sheet.columns
    for i in range(0, len(periods)):
      if (self.income_statement[periods[i]]['totalRevenue'] == None or self.income_statement[periods[i]]['costOfRevenue'] == None):
        print("totalRevenue or costOfRevenue is Nonr for ", i)
        return None
      tr = self.income_statement[periods[i]]['totalRevenue']
      cr = self.income_statement[periods[i]]['costOfRevenue']
      self.gm_raw.append((tr-cr)/tr)
    return self.gm_raw

