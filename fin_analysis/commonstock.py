from numerize import numerize
class CommonStock:
  def __init__(self, balance_sheet=None, income_statement=None, cfs=None):
    self.balance_sheet=balance_sheet
    self.income_statement = income_statement
    self.cfs = cfs
    self.cs=[]
    self.cs_raw=[]
  def get_cs(self):
    periods = self.balance_sheet.columns
    for i in range(0, len(periods)):
      if('commonStock' not in self.balance_sheet[periods[i]]):
        print("Key commonStock is none for i ", i)
        return None
      cs = self.balance_sheet[periods[i]]['commonStock']
      self.cs.append(numerize.numerize(float(cs),2))

    return self.cs
  def get_cs_raw(self):
    periods = self.balance_sheet.columns
    for i in range(0, len(periods)):
      if('commonStock' not in self.balance_sheet[periods[i]]):
        print("Key commonStock is none for i ", i)
        return None
      cs_raw = self.balance_sheet[periods[i]]['commonStock']
      self.cs_raw.append(cs_raw)

    return self.cs_raw

