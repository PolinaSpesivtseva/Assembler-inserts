#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
	setlocale(LC_ALL, "RUS"); //���������� ������� ����
	setlocale(LC_NUMERIC, "ENG");
	printf("������� ������, ��������� �� ���� ���������� ���� ��� ��������:\n");
	char x1, x2, x3, x4;
	char str[5];
IN: gets(str); //���� ������ �������������
	x1 = str[0];
	x2 = str[1];
	x3 = str[2];
	x4 = str[3];
	for (int i = 0; i < strlen(str); i++) //�������� �� �������� �������
		if (str[i] < '0' || str[i]>'9' || strlen(str) != 4)
		{
			printf("�������� ����! ������� ������ ����� �� 0 �� 9.\n");
			goto IN; //������� �� ��������� ����
		}
	__asm
	{
		mov al, x1; //��������� x1 � al
		sub al, 48; //�������� ��� ����, �������� ����� � 16����� ������� 
		mov bl, x2; //��������� x2 � bl
		sub bl, 48;
		mov cl, x3; //��������� x3 � cl
		sub cl, 48;
		mov dl, x4; //��������� x4 � dl
		sub dl, 48;


		cmp al, bl; //���������� ������ � ������ �����
		je A; //���� ������ ����� ������, ��������� �� ����� A
		jmp E; //����� ��������� �� ����� E

	A: cmp al, dl; //���������� ������ � ��������� �����
		jge B; //���� ������ �� ������ ���������, �� ��������� �� ����� B
		jmp E; //����� ��������� �� ����� E

	B:
		cmp al, 9; // ���������� ������ ����� � 9
		jl F; //���� ����� ������ 9, �� ��������� �� ����� �
		jmp D; //���� ��� 9 �� ��������� �� D
	D:
		add al, 0; // �� ������ ������ �����
		jmp fin; //��������� �� ��������� �����
	F:
		add al, 1; //���������� 1 � ������ �����
		jmp fin; //��������� �� ��������� �����

	E:
		mov cl, 3; //�������� 3,4 ����� ��������
		mov dl, 3;
		jmp fin; //��������� �� ��������� �����
	fin:			//��������� �����
		add al, 48; //���������� ��� 0 �� ������� ASCII
		mov x1, al; //����� �������� ���������� ��� ������
		add bl, 48;
		mov x2, bl;
		add cl, 48;
		mov x3, cl;
		add dl, 48;
		mov x4, dl;
	}
	printf("���������� ������:\n%c%c%c%c\n", x1, x2, x3, x4); //����� ���������� ������ �� �����
	goto IN;
	return 0;
}
