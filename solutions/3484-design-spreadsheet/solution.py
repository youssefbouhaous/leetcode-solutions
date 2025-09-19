from collections import defaultdict
class Spreadsheet:

    def __init__(self, rows: int):
        self.d = defaultdict(int)

    def setCell(self, cell: str, value: int) -> None:
        self.d[cell] = value

    def resetCell(self, cell: str) -> None:
        self.d[cell] = 0

    def getValue(self, formula: str) -> int:
        p = formula[1:].split("+")
        ans = 0
        for i in p:
            if i.isdigit():
                ans+=int(i)
            else:
                ans+=self.d[i]
        return ans


# Your Spreadsheet object will be instantiated and called as such:
# obj = Spreadsheet(rows)
# obj.setCell(cell,value)
# obj.resetCell(cell)
# param_3 = obj.getValue(formula)