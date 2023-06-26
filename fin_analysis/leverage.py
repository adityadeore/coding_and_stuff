from numerize import numerize
class Leverage:
  def __init__(self, balance_sheet=None, income_statement=None, cfs=None):
    self.balance_sheet=balance_sheet
    self.income_statement = income_statement
    self.cfs = cfs
    self.leverage=[]
    self.leverage_raw=[]
  def get_leverage(self):
    periods = self.balance_sheet.columns
    for i in range(0, len(periods)):
      if ('longTermDebt' not in self.balance_sheet[periods[i]] or 'totalStockholderEquity' not in self.balance_sheet[periods[i]]):
        print('longTermDebt or totalStockholderEquity is None for ', i)
        return None
      ltd = self.balance_sheet[periods[i]]['longTermDebt']
      seq = self.balance_sheet[periods[i]]['totalStockholderEquity']
      self.leverage.append(numerize.numerize(float(ltd/seq),2))
    return self.leverage

  def get_leverage_raw(self):
    periods = self.balance_sheet.columns
    for i in range(0, len(periods)):
      if ('longTermDebt' not in self.balance_sheet[periods[i]] or 'totalStockholderEquity' not in self.balance_sheet[periods[i]]):
        print('longTermDebt or totalStockholderEquity is None for ', i)
        return None
      ltd = self.balance_sheet[periods[i]]['longTermDebt']
      seq = self.balance_sheet[periods[i]]['totalStockholderEquity']
      self.leverage_raw.append(ltd/seq)
    return self.leverage_raw

