import requests

class Table():
	def __init__(self):
		self._dirty = False
		self._busy = False

	def isBusy(self):
		return self._busy

	def isDirty(self):
		return self._dirty

	def setBusy(self, value):
		if self._busy != value:
			self._busy = value

	def setDirty(self, value):
		if self._dirty != value:
			self._dirty = value

	def update(self, value):
		if value == 1:
			self.setDirty(True)
		elif value == 2:
			self.setDirty(False)
			self.setBusy(True)
		elif value == 3:
			self.setDirty(False)
			self.setBusy(False)
