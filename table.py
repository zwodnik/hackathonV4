import requests

class Table():
<<<<<<< HEAD
	def __init__(self, id):
		self._dirty = False
		self._busy = False
		self._id = id
=======
	def __init__(self):
		self._dirty = False
		self._busy = False
>>>>>>> 0d9b1147483227f943b7e8b45c004716d68081cc

	def isBusy(self):
		return self._busy

	def isDirty(self):
		return self._dirty

	def setBusy(self, value):
		if self._busy != value:
			self._busy = value
<<<<<<< HEAD
			self.sendRequests()
=======
>>>>>>> 0d9b1147483227f943b7e8b45c004716d68081cc

	def setDirty(self, value):
		if self._dirty != value:
			self._dirty = value
<<<<<<< HEAD
			self.sendRequests()

	def sendRequests(self):
		if self.isDirty() is True:
			requests.put('http://10.10.4.89:8080/api/spots/wet/{0}'.format(self._id))
		elif self.isDirty() is False:
			requests.put('http://10.10.4.89:8080/api/spots/notwet/{0}'.format(self._id))
		if self.isBusy() is True:
			requests.put('http://10.10.4.89:8080/api/spots/taken/{0}'.format(self._id))
		elif self.isBusy() is False:
			requests.put('http://10.10.4.89:8080/api/spots/free/{0}'.format(self._id))
=======
>>>>>>> 0d9b1147483227f943b7e8b45c004716d68081cc

	def update(self, value):
		if value == 1:
			self.setDirty(True)
<<<<<<< HEAD
		if value == 2:
=======
		elif value == 2:
>>>>>>> 0d9b1147483227f943b7e8b45c004716d68081cc
			self.setDirty(False)
			self.setBusy(True)
		elif value == 3:
			self.setDirty(False)
			self.setBusy(False)
