void shuffle(int cards[], int n) 
{  
	if (cards == NULL)   
		return; 
 	srand(time(0));  
	for (int i = 0; i<n - 1; ++i)  
	{   
		//��֤ÿ�ε� i λ��ֵ�����漰���� i λ��ǰ   
		int index = i + rand() % (n - i); 
		int temp = cards[i];   	
		cards[i] = cards[index];   
		cards[index] = temp;  
	} 
}