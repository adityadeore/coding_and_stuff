'''
Module to caclulate the Free cash flow of a company

'''

def required_investments_in_working_capital(self):
  periods = self.balance_sheet.columns
  operatingcurrentassets=[]
  operatingcurrentliabilities=[]
  for i in range(0, len(periods)):
    cash = self.balance_sheet[periods[i]]['cash']
    accnt_rxvable = self.balance_sheet[periods[i]]['netReceivables']
    inventory = self.balance_sheet[periods[i]]['inventory']
    operatingcurrentassets.append(cash+accnt_rxvable+inventory)

    accnt_payable=self.balance_sheet[periods[i]]['accountsPayable']
    accruals = self.balance_sheet[periods[i]]['totalCurrentLiabilities']
    operatingcurrentliabilities.append(accnt_payable+accruals)

  #print(operatingcurrentassets)
  #print(operatingcurrentliabilities)
  net_workingcapital=[]
  for i  in range(0, len(operatingcurrentliabilities)):
    net_workingcapital.append(operatingcurrentassets[i]-operatingcurrentliabilities[i])
  #print(net_workingcapital)
  TotalNetOperatingCapital=[]
  plantpropertyequip=[]
  for i  in range(0, len(periods)):
    plantpropertyequip.append(self.balance_sheet[periods[i]]['propertyPlantEquipment'])

  #print(plantpropertyequip)
  for i in range(0, len(plantpropertyequip)):
    TotalNetOperatingCapital.append(net_workingcapital[i] + plantpropertyequip[i])

  #print(TotalNetOperatingCapital)
  RequiredIinvetmentsinOperatingCapital=[]
  for i in range(0, len(periods)-1):
    RequiredIinvetmentsinOperatingCapital.append(TotalNetOperatingCapital[i+1] - TotalNetOperatingCapital[i])

  return RequiredIinvetmentsinOperatingCapital

class Fcf:
  def __init__(self, balance_sheet=None, income_statement=None, cfs=None):
    self.balance_sheet=balance_sheet
    self.income_statement = income_statement
    self.cfs = cfs
    self.fcfs=[]

  def get_fcf_sales_revenue(self):
    # https://www.investopedia.com/ask/answers/033015/what-formula-calculating-free-cash-flow.asp
#    if(self.balance_sheet.empty() or self.cfs.empty() or self.income_statement.empty()):
#      print("Unable to find data")
#      return

    periods = self.balance_sheet.columns

    RequiredIinvetmentsinOperatingCapital= required_investments_in_working_capital(self)
    FreeCashFlow=[]
    for i in range(0, len(periods)-1):
      sales_revenue = self.income_statement[periods[i]]['totalRevenue']
      operating_costs = self.income_statement[periods[i]]['totalOperatingExpenses']
      taxes = self.income_statement[periods[i]]['incomeTaxExpense']
      FreeCashFlow.append(sales_revenue - operating_costs + taxes-RequiredIinvetmentsinOperatingCapital[i])

    return FreeCashFlow

  def fcf_net_profits(self):
    periods = self.balance_sheet.columns
    NetOperatingProfitAfterTaxes=[]
    Taxrate=[]
    for period in periods:
      taxexpense = self.income_statement[period]['incomeTaxExpense']
      incomebeforetaxes = self.income_statement[period]['incomeBeforeTax']
      Taxrate.append(taxexpense/incomebeforetaxes)
    for i, period in enumerate(periods):
      operatingincome= self.income_statement[period]['operatingIncome']
      NetOperatingProfitAfterTaxes.append(operatingincome * (1-Taxrate[i]))

    RequiredIinvetmentsinOperatingCapital= required_investments_in_working_capital(self)
    FreeCashFlow=[]
    for i in range(0,len(RequiredIinvetmentsinOperatingCapital)):
      FreeCashFlow.append(NetOperatingProfitAfterTaxes[i]-RequiredIinvetmentsinOperatingCapital[i])

    return FreeCashFlow

  def fcf_operating(self):
    periods = self.balance_sheet.columns
    OperatingCashFlow=[]
    CapitalExpenditures=[]
    FreeCashFlow=[]
    for period in periods:
      OperatingCashFlow = self.cfs[period]['totalCashFromOperatingActivities']
      CapitalExpenditures = self.cfs[period]['capitalExpenditures']
      FreeCashFlow.append(OperatingCashFlow + CapitalExpenditures)

    return FreeCashFlow


