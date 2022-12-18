#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<string.h>

void gotoxy(int x, int y)
{
    static HANDLE  h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x,y};
    SetConsoleCursorPosition(h,c);
}

void SetTeColor( WORD color)
{ 
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0; wAttributes |= color;
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}


char inTungChu(char chuoi[], int n){
	int i;
	for (i=0; i< strlen(chuoi); i++)
	{
		SetTeColor(n);
		printf("%c", chuoi[i]);
		Sleep(20);
		n+=1;
		if (n==15) n=1;
	}
}

char inCaChu(char chuoi[], int n){
	int i;
	for (i=0; i< strlen(chuoi); i++)
	{
		SetTeColor(n);
		printf("%c", chuoi[i]);
		Sleep(100);
		if (chuoi[i]==' ') n+=1;;
		if (n==15) n=1;
	}
}

int main(){
	int i, a=50, b=1, n=1, doi=1;
	char chuoi1[]="Happy Birth Day To Me!!!";
	char chuoi2[]="Happy Birth Day... ";
	while (1)
	{
		doi+=1;
		if (doi%3==1)
		{
			for (i=1;i<=2;i++){
			gotoxy(a, b);
			inTungChu(chuoi1, n);
			b++;
			}
			gotoxy(a-4,b);
				printf(".....%c ..%c%c ...%c%c%c... %c%c.. %c.....", (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14);
			gotoxy(a-8,b+1);
			for (i=1;i<=2;i++){
				inTungChu(chuoi2, n);
				printf("\t");
			}
			gotoxy(a-2,b+3);
				printf("...%c ..%c%c ...%c%c%c... %c%c.. %c...", (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14);
			gotoxy(a,b+5);
				inTungChu(chuoi1, n);	
			n++;
			a=50, b=1;
		}
		if (doi%3==2)
		{
			for (i=1;i<=2;i++){
				gotoxy(a, b);
				inCaChu(chuoi1, n);
				b++;
			}
			gotoxy(a-4,b);
				printf(".....%c ..%c%c ...%c%c%c... %c%c.. %c.....", (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14);
			gotoxy(a-8,b+1);
			for (i=1;i<=2;i++){
				inCaChu(chuoi2, n);
				printf("\t");
			}
			gotoxy(a-2,b+3);
				printf("...%c ..%c%c ...%c%c%c... %c%c.. %c...", (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14);
			gotoxy(a,b+5);
				inCaChu(chuoi1, n);	
			n++;
			a=50, b=1;
		}
		if (doi%3==0)
		{
			for (i=1;i<=2;i++){
				gotoxy(a, b);
				SetTeColor(b);
				printf("%s", chuoi1);
				Sleep(100);
				b++;
			}
			gotoxy(a-4,b);
				SetTeColor(b);
				Sleep(100);
				printf(".....%c ..%c%c ...%c%c%c... %c%c.. %c.....", (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14);
			gotoxy(a-8,b+1);
			for (i=1;i<=2;i++){
				printf("%s", chuoi2);
				SetTeColor(b+2);
				Sleep(100);
				printf("\t");
			}
			gotoxy(a-2,b+3);
				SetTeColor(b+5);
				Sleep(100);
				printf("...%c ..%c%c ...%c%c%c... %c%c.. %c...", (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14, (char) 14);
			gotoxy(a,b+5);
				SetTeColor(b+7);
				Sleep(100);
				printf("%s", chuoi1);
			n++;
			a=50, b=1;
		}
	}
	getch();
	return 0;
}
