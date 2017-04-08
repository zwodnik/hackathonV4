import requests

class Table():
	def __init__(self, id):
		self._dirty = False
		self._busy = False
		self._id = id

	def isBusy(self):
		return self._busy

	def isDirty(self):
		return self._dirty

	def setBusy(self, value):
		if self._busy != value:
			self._busy = value
			self.sendRequests()

	def setDirty(self, value):
		if self._dirty != value:
			self._dirty = value
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

	def update(self, value):
		if value == 1:
			self.setDirty(True)
		if value == 2:
			self.setDirty(False)
			self.setBusy(True)
		elif value == 3:
			self.setDirty(False)
			self.setBusy(False)
