from numerize import numerize

class Ocf:
  def __init__(self, balance_sheet=None, income_statement=None, cfs=None):
    self.balance_sheet=balance_sheet
    self.income_statement = income_statement
    self.cfs = cfs
    self.ocfs=[]
    self.ocfs_raw=[]
  def get_ocf(self):
    periods = self.balance_sheet.columns
    for i in range(0, len(periods)):
      if(self.cfs[periods[i]]['totalCashFromOperatingActivities'] == None):
        print('totalCashFromOperatingActivities is None for ', i)
        return None
      operatingCF = self.cfs[periods[i]]['totalCashFromOperatingActivities']
      self.ocfs.append(numerize.numerize(float(operatingCF),2))

    return self.ocfs
  def get_ocf_raw(self):
    periods = self.balance_sheet.columns
    for i in range(0, len(periods)):
      if(self.cfs[periods[i]]['totalCashFromOperatingActivities'] == None):
        print('totalCashFromOperatingActivities is None for ', i)
        return None
      operatingCF = self.cfs[periods[i]]['totalCashFromOperatingActivities']
      self.ocfs_raw.append(operatingCF)

    return self.ocfs_raw

