try:
    import sys
    n , h = map(int, sys.stdin.readline().strip().split())
    boxes = list(map(int , sys.stdin.readline().strip().split()))
    seq = list(map(int , sys.stdin.readline().strip().split()))
    
    i = 0
    j = 0
    k = 0
    hold = 0
    
    for s in seq: 
    	if s == 0:
    		i=1
    		break
    
    	elif s == 3:
    		if boxes[j] > 0 and hold == 0:
    			k = 1
    			boxes[j] -= 1
    			hold = 1
    
    	elif s == 4:
    		if boxes[j] + k <= h and hold == 1:
    			boxes[j] += k
    			k=0
    			hold = 0
    
    	elif s == 1:
    		if j != 0:
    			j -= 1
    
    	elif s == 2:
    		if j != n-1:
    			j += 1
    
    	
    res = ''
    for b in boxes:
    	res += str(b) + ' ' 
    print(res)
except : pass
