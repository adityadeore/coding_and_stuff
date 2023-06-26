import yahoo_fin.stock_info as yf

class Statements:
  def __init__(self, ticker, yearly=True):
    self.ticker = ticker
    self.yearly = yearly
  def get_statements(self):
    balance_sheet = yf.get_balance_sheet(self.ticker, self.yearly)
    income_statement = yf.get_income_statement(self.ticker, self.yearly)
    cfs = yf.get_cash_flow(self.ticker, self.yearly)
    return [balance_sheet, income_statement, cfs]

