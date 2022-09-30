class Stack :
	
	def __init__(self):
		self.items = []
	
	def is_empty(self):
		return self.items == []
		
	def push(self,item):
		self.items.append(item)	
    
	def pop(self):
		return self.items.pop()
		
	def peek(self):
		return self.items[len(self.items)-1]
	
	def size(self):
		return len(self.items)

	

## Sample inputs
if __name__ == '__main__':
	
	s=Stack()
	
	while True :
		print('PROGRAM STACK PYTHON')
		print('1.PUSH\n2.POP\n3.TOP\n4.SIZE');
		
		pilih = int(input('Pilih Menu : '));
	
		if pilih==1:
			push = input("masukkan data ke stack : ");
			s.push(push);
		elif pilih==2:
			print("mengeluarkan data  : ",s.pop());
		elif pilih==3:
			print('Data paling atas yaitu : ',s.peek())

		elif pilih==4:
			print("ukuran stack adalah : ",s.size());
		else:
			break;

