int main() {

	int x = 3;
	int y = 6;
	int vf1, vf2;
	int e1, e2, e3;
	
	/* Responda se a expressão é verdadeira ou falsa */
	vf1 = 10 > 5 && !(10 < 9) || (3 <= 2 + 1);
	vf2 = !(x - 2) < y + 3 && y - x * 2;
	
	/* Dê os valores finais de x e y em cada expressão: */
	e1 = x * 3;
	e2 = y + (x - y);
	e3 = ++y;

	/*
	vf1 = (10 > 5) e não(10 < 9) ou (3 <= 2 + 1)
			= [SIM e não(NÃO)] ou [3 <= 3] 
			= [SIM e SIM] ou [SIM]
			= SIM ou SIM
			= SIM = 1
	vf2 = não[(x – 2) < (y + 3)] e [y – x * 2]
			= não[(3 - 2) < (6 + 3)] e [6 - 3 * 2]
			= não[1 < 9] e [6 - 6]
			= não[SIM] e 0
			= NÃO e NÃO
			= NÃO = 0
	
	e1 = 3 * 3
	   = 9
	
	e2 = 6 + (3 - 6)
		 = 6 - 3
		 = 3 
	
	e3 = 1 + 6
		 = 7
		 y = 7 
	*/
	return 0;
}
