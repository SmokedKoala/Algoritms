#include <cstdio>
#include <iostream>
#include <Windows.h>


using namespace std;


int n = 0; // ����������� � ������� �����   
int arr[ 100 ] = { 0 }; // ������
int num = 0; // ���������� ��������� � �������
int h = 0;//������ �������
int t = 0;//����� �������

void addNum (){
	cin>>arr[t];
    printf( "� ������� ������� %d ������� ����� %d \n", ( t ), arr[ t ]  );
    t++;
    if( t == 100 )
    {
        t = t - 100;
    }
    num++;
//    printf( "����� ������ ����� �������: %d \n", t  );
//    printf( "������ ������ �������: %d \n", h );
    printf( "����� ������� ������� �������: %d \n\n", num );
}

void delNum(){
	printf( " �� ������� ������� %d ��������� ��������: %d \n", h, arr[ h ]);
    num--;
    h++;
    if( h == 100 )
        {
        	h = ( h - 100 );
        }
}

void printQueue(){
	cout<<endl<<"�������: ";
	if (h<t)
		for(int i = h; i<t;i++){
			cout << arr[i]<<" ";
		}
	else{
		for (int i=h;i<100;i++)
			cout << arr[i]<<" ";
		for (int i=0;i<t;i++)	
			cout << arr[i]<<" ";
	}
	cout<<endl;
}

void findElement(int number){
	bool check=false;
	for (int i =h; i<num;i++)
		if (number==arr[i]){
			cout<<"������� "<<number<<" ������ �� ������� "<<i<<endl;
			check=true;
	}
	if(!check)
		cout<<"������� �� ������"<<endl;
}

int main( void ) 
{
	int subN,element;
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout
            << "������������ ������ �8. �������, �����, ����. ������ ����������, ����-08-19"
            << endl;
    cout<<"������� 10 ��������� ������: ";
    for (int i =0; i<10;i++) addNum();
	while( true )
    {
      cout<<endl<<"1-�������� �����" <<endl<<"2-������ �����"<<endl<<"3-����� �������  "<<endl<<"4-������� �������  "<<endl<<"0-����� �� ���������  "<<endl;
      cout<<endl<<"������� �";
	  cin>>n;
      switch (n)
      {
		case 2:
      		{
          	if( num == 0 )
          		{
               printf( "������� �����! \n" );
          		}
          	else
          		{
              delNum();
          		}
          
      		break;
			}
      	
      	case 1:
      		{
          	if( num < 100 )
          	{
          		cout<< "������ �����:" ;
              	addNum();
               
          	}
          	else if( num == 100 )
          	{
            	printf( "������� ��������� \n\n" );
          	}
      		break;
		  	}
      	case 4:
		  printQueue();
		  break;	
      	case 0:
      		return 0;
      		break;
      	case 3:
      		cout<<"     3.1-��������� ������� ���� "<<endl<<"     3.2-���������� �������� ��� "<<endl;
      		cout<<endl<<"������� �";
      		cin>>subN;
      		switch (subN){
      			case 1:
      				cout<<"������� ������� ��� ������ ";
      				cin>>element;
      				findElement(element);
      				break;
      			case 2:
				  	findElement(999999);	
			  }
      		break;
		}
	}
	return 0;
}
