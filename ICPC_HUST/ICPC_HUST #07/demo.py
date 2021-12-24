def check(se):
	a = se.find('@', 1)
	if a <= 0: return False
	dot = se.find('.', a + 2)
	if dot == -1 or dot == len(se) - 1: return False
	return True
	
if __name__ == '__main__':
	se = input()
	if check(se): print("Yes")
	else: print("No")
