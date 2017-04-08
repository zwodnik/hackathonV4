import subprocess
from table import Table
import re

import time


def display(idT,table):
	print("ID: {0}".format(idT))
	print("isDirty: {0}".format(table.isDirty()))
	print("isBusy: {0}".format(table.isBusy()))
	print("")


list_tables = []

list_tables.append(Table(1802))
list_tables.append(Table(1451))

while True:
	try:
		a = subprocess.check_output("./transfer")
		ret = str(a)
		ret = re.findall('.',ret)
	
		idTable = int(ret[0])-1
		#print(list_tables[int(ret[0])])
		list_tables[idTable].update(int(ret[1]))

		display(idTable,list_tables[idTable])
		time.sleep(1)
	except:
		pass


