from numerize import numerize

class Roa:
  def __init__(self, balance_sheet=None, income_statement=None, cfs=None):
    self.balance_sheet=balance_sheet
    self.income_statement = income_statement
    self.cfs = cfs
    self.roas=[]
    self.roas_raw=[]
  def get_roa(self):
    periods = self.balance_sheet.columns
    #print(self.balance_sheet)
    #print(periods)
    for i in range(0, len(periods)):
      if(self.income_statement[periods[i]]['netIncomeFromContinuingOps'] == None or self.balance_sheet[periods[i]]['totalAssets'] == None):
        print('netIncomeFromContinuingOps or totalAssets is None for ', i)
        return None
      netincome = self.income_statement[periods[i]]['netIncomeFromContinuingOps']
      totalassets = self.balance_sheet[periods[i]]['totalAssets']
      self.roas.append(numerize.numerize(float(netincome/totalassets),2))
                        
    return self.roas
  def get_roa_raw(self):
    periods = self.balance_sheet.columns
    #print(self.balance_sheet)
    #print(periods)
    for i in range(0, len(periods)):
      if(self.income_statement[periods[i]]['netIncomeFromContinuingOps'] == None or self.balance_sheet[periods[i]]['totalAssets'] == None):
        print('netIncomeFromContinuingOps or totalAssets is None for ', i)
        return None
      netincome = self.income_statement[periods[i]]['netIncomeFromContinuingOps']
      totalassets = self.balance_sheet[periods[i]]['totalAssets']
      self.roas_raw.append(netincome/totalassets)

    return self.roas_raw

