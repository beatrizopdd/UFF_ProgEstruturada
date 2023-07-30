int main () {

	int x, y, z;
	int t1, t2, t3, t4;
	
	x = 5;
	y = x++;
	z = x--;
	
	/*
	x = 5
	
	y = 5
	x = 6
	
	z = 6
	x = 5
	*/
	
	/* Informe os valores de teste, x, y e z depois da avaliação das seguintes expressões: */ 
	t1 = !y == !x;
	t2 = ((x++ > y) || (--z <= y));
	t3 = ((!x) || (!(!z)));
	t4 = (((x + y) > z) && (x++));

	/*
	t1 = !y == !x
		 = !5 == !5
		 = 0 == 0
		 = SIM
		 = 1
	
	t2 = ((x++ > y) || (--z <= y))
		 = (5 > 5) ou (5 <= 5)
		 = NÃO ou SIM
		 = SIM 
		 = 1
		 
	t3 = ((!x) || (!(!z)))
		 = (!6) ou [!(!5)]
		 = NÃO ou não(NÃO)
		 = NÃO ou SIM
		 = SIM
		 = 1
		 
	t4 = (((x + y) > z) && (x++))
		 = [(6 + 5) > 5] e (6)
		 = [11 > 5] e 6
		 = SIM e SIM 
		 = SIM
		 = 1
	*/
	
	return 0;
}
