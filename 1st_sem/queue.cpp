#include <cstdio>
#include <iostream>
#include <Windows.h>


using namespace std;


int n = 0; // Сохраняемое в массиве число   
int arr[ 100 ] = { 0 }; // Массив
int num = 0; // Количество элементов в очереди
int h = 0;//начало очереди
int t = 0;//конец очереди

void addNum (){
	cin>>arr[t];
    printf( "В элемент очереди %d внесено число %d \n", ( t ), arr[ t ]  );
    t++;
    if( t == 100 )
    {
        t = t - 100;
    }
    num++;
//    printf( "Новый индекс конца очереди: %d \n", t  );
//    printf( "Индекс начала очереди: %d \n", h );
    printf( "Число занятых позиций очереди: %d \n\n", num );
}

void delNum(){
	printf( " Из позиции очереди %d извлечено значение: %d \n", h, arr[ h ]);
    num--;
    h++;
    if( h == 100 )
        {
        	h = ( h - 100 );
        }
}

void printQueue(){
	cout<<endl<<"Очередь: ";
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
			cout<<"Элемент "<<number<<" найден на позиции "<<i<<endl;
			check=true;
	}
	if(!check)
		cout<<"Элемент не найден"<<endl;
}

int main( void ) 
{
	int subN,element;
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout
            << "Практическая работа №8. Очереди, стеки, деки. Азаров Константин, ИКБО-08-19"
            << endl;
    cout<<"Введите 10 элементов очреди: ";
    for (int i =0; i<10;i++) addNum();
	while( true )
    {
      cout<<endl<<"1-добавить число" <<endl<<"2-убрать число"<<endl<<"3-найти элемент  "<<endl<<"4-вывести очередь  "<<endl<<"0-выйти из программы  "<<endl;
      cout<<endl<<"Команда №";
	  cin>>n;
      switch (n)
      {
		case 2:
      		{
          	if( num == 0 )
          		{
               printf( "Очередь пуста! \n" );
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
          		cout<< "Ввести число:" ;
              	addNum();
               
          	}
          	else if( num == 100 )
          	{
            	printf( "Очередь заполнена \n\n" );
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
      		cout<<"     3.1-поисковой элемент есть "<<endl<<"     3.2-поискового элемента нет "<<endl;
      		cout<<endl<<"Команда №";
      		cin>>subN;
      		switch (subN){
      			case 1:
      				cout<<"Введите элемент для поиска ";
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
