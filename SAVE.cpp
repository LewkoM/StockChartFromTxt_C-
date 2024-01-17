#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

void wczytanieAAPL(double tabdane[][400], double &buflow, double &bufhigh)
{
	int iloscdni;
	string danedata;
	string datastart;
	string bufor;
	double open, high, low, close;
	cout<<"Wprowadz date(rok-miesiac-dzien) od ktorej ma sie wyswietlac wykres."<<endl;
	cin>>datastart;
	cout<<"Podaj ilosc dni od wyznaczonej daty, ktore chcesz wczytac: ";
	cin>>iloscdni;
	cout<<endl;
	ifstream plik1 ("AAPL.txt");
	

    if(!plik1)
    {
        cout << "Plik nie otwarty!" << endl;
        exit (1);
    }
    getline(plik1,danedata,',');
	while(datastart!=danedata)
	{
		getline(plik1,bufor);
   		getline(plik1,danedata,',');
   	}
	int wybor;
	cout<<"Wybierz sposob wyswietlania wykresu:"<<endl;
	cout<<"1.Dzien po dniu-zgodnie z plikiem"<<endl<<"2.Manualnie np. co trzy dni, co tydzien"<<endl;
	cin>>wybor;
	int probki=1;
	switch(wybor)
	{
		case 1:
			{
				if(iloscdni<=400)
				{
					for(int i=0; i<iloscdni; i++)
					{
						getline(plik1,bufor,',');
						plik1>>open;
						tabdane[0][i]=open;
						getline(plik1,bufor,',');
						plik1>>high;
						tabdane[1][i]=high;
						if(bufhigh<high)
						{
							bufhigh=high;
						}
						getline(plik1,bufor,',');
						plik1>>low;
						tabdane[2][i]=low;
						if(buflow>low)
						{
							buflow=low;
						}
						getline(plik1,bufor,',');
						plik1>>close;
						tabdane[3][i]=close;
						getline(plik1,bufor); //przejscie do nastepnej linijki
					}	
				}
				else
				{
					probki=(iloscdni/400)+1;
					for(int i=0; i<(iloscdni/probki); i++)
					{
						double open1=0, high1=0, low1=0, close1=0;
						for(int j=0; j<probki; j++)
						{
							getline(plik1,bufor,',');
							plik1>>open;
							open1=open1+open;
							getline(plik1,bufor,',');
							plik1>>high;
							high1=high1+high;
							getline(plik1,bufor,',');
							plik1>>low;
							low1=low1+low;
							getline(plik1,bufor,',');
							plik1>>close;
							close1=close1+close;
							getline(plik1,bufor);
						}
						tabdane[0][i]=open1/probki;
						tabdane[1][i]=high1/probki;
						tabdane[2][i]=low1/probki;
						tabdane[3][i]=close1/probki;
						if(bufhigh<high1/probki)
						{
							bufhigh=high1/probki;
						}
						if(buflow>low1/probki)
						{
							buflow=low1/probki;
						}
					}
				}
			}
			break;
			
		case 2:
			{
				int dni;
				cout<<"Co ile dni wykreslac?"<<endl;
				cin>>dni;
				for(int i=0; i<iloscdni/dni; i++)
					{
						double open1=0, high1=0, low1=0, close1=0;
						for(int j=0; j<dni; j++)
						{
							getline(plik1,bufor,',');
							plik1>>open;
							open1=open1+open;
							getline(plik1,bufor,',');
							plik1>>high;
							high1=high1+high;
							getline(plik1,bufor,',');
							plik1>>low;
							low1=low1+low;
							getline(plik1,bufor,',');
							plik1>>close;
							close1=close1+close;
							getline(plik1,bufor);
						}
						tabdane[0][i]=open1/dni;
						tabdane[1][i]=high1/dni;
						tabdane[2][i]=low1/dni;
						tabdane[3][i]=close1/dni;
						if(bufhigh<high1/dni)
						{
							bufhigh=high1/dni;
						}
						if(buflow>low1/dni)
						{
							buflow=low1/dni;
						}
					}
			}
	}
	

	plik1.close();
}
void wczytanieINTC(double tabdane[][400], double &buflow, double &bufhigh)
{
	int iloscdni;
	string danedata;
	string datastart;
	string bufor;
	double open, high, low, close;
	cout<<"Wprowadz date(rok-miesiac-dzien) od ktorej ma sie wyswietlac wykres."<<endl;
	cin>>datastart;
	cout<<"Podaj ilosc dni od wyznaczonej daty, ktore chcesz wczytac: ";
	cin>>iloscdni;
	cout<<endl;
	ifstream plik1 ("INTC.txt");
	

    if(!plik1)
    {
        cout << "Plik nie otwarty!" << endl;
        exit (1);
    }
    getline(plik1,danedata,',');
	while(datastart!=danedata)
	{
		getline(plik1,bufor);
   		getline(plik1,danedata,',');
   	}
	int wybor;
	cout<<"Wybierz sposob wyswietlania wykresu:"<<endl;
	cout<<"1.Dzien po dniu-zgodnie z plikiem"<<endl<<"2.Manualnie np. co trzy dni, co tydzien"<<endl;
	cin>>wybor;
	int probki=1;
	switch(wybor)
	{
		case 1:
			{
				if(iloscdni<=400)
				{
					for(int i=0; i<iloscdni; i++)
					{
						getline(plik1,bufor,',');
						plik1>>open;
						tabdane[0][i]=open;
						getline(plik1,bufor,',');
						plik1>>high;
						tabdane[1][i]=high;
						if(bufhigh<high)
						{
							bufhigh=high;
						}
						getline(plik1,bufor,',');
						plik1>>low;
						tabdane[2][i]=low;
						if(buflow>low)
						{
							buflow=low;
						}
						getline(plik1,bufor,',');
						plik1>>close;
						tabdane[3][i]=close;
						getline(plik1,bufor); //przejscie do nastepnej linijki
					}	
				}
				else
				{
					probki=(iloscdni/400)+1;
					for(int i=0; i<iloscdni/probki; i++)
					{
						double open1=0, high1=0, low1=0, close1=0;
						for(int j=0; j<probki; j++)
						{
							getline(plik1,bufor,',');
							plik1>>open;
							open1=open1+open;
							getline(plik1,bufor,',');
							plik1>>high;
							high1=high1+high;
							getline(plik1,bufor,',');
							plik1>>low;
							low1=low1+low;
							getline(plik1,bufor,',');
							plik1>>close;
							close1=close1+close;
							getline(plik1,bufor);
						}
						tabdane[0][i]=open1/probki;
						tabdane[1][i]=high1/probki;
						tabdane[2][i]=low1/probki;
						tabdane[3][i]=close1/probki;
						if(bufhigh<high1/probki)
						{
							bufhigh=high1/probki;
						}
						if(buflow>low1/probki)
						{
							buflow=low1/probki;
						}
					}
				}
			}
			break;
			
		case 2:
			{
				int dni;
				cout<<"Co ile dni wykreslac?"<<endl;
				cin>>dni;
				for(int i=0; i<iloscdni/dni; i++)
					{
						double open1=0, high1=0, low1=0, close1=0;
						for(int j=0; j<dni; j++)
						{
							getline(plik1,bufor,',');
							plik1>>open;
							open1=open1+open;
							getline(plik1,bufor,',');
							plik1>>high;
							high1=high1+high;
							getline(plik1,bufor,',');
							plik1>>low;
							low1=low1+low;
							getline(plik1,bufor,',');
							plik1>>close;
							close1=close1+close;
							getline(plik1,bufor);
						}
						tabdane[0][i]=open1/dni;
						tabdane[1][i]=high1/dni;
						tabdane[2][i]=low1/dni;
						tabdane[3][i]=close1/dni;
						if(bufhigh<high1/dni)
						{
							bufhigh=high1/dni;
						}
						if(buflow>low1/dni)
						{
							buflow=low1/dni;
						}
					}
			}
	}
	

	plik1.close();
}
void wczytanieMSFT(double tabdane[][400], double &buflow, double &bufhigh)
{
	int iloscdni;
	string danedata;
	string datastart;
	string bufor;
	double open, high, low, close;
	cout<<"Wprowadz date(rok-miesiac-dzien) od ktorej ma sie wyswietlac wykres."<<endl;
	cin>>datastart;
	cout<<"Podaj ilosc dni od wyznaczonej daty, ktore chcesz wczytac: ";
	cin>>iloscdni;
	cout<<endl;
	ifstream plik1 ("MSFT.txt");
	

    if(!plik1)
    {
        cout << "Plik nie otwarty!" << endl;
        exit (1);
    }
    getline(plik1,danedata,',');
	while(datastart!=danedata)
	{
		getline(plik1,bufor);
   		getline(plik1,danedata,',');
   	}
	int wybor;
	cout<<"Wybierz sposob wyswietlania wykresu:"<<endl;
	cout<<"1.Dzien po dniu-zgodnie z plikiem"<<endl<<"2.Manualnie np. co trzy dni, co tydzien"<<endl;
	cin>>wybor;
	int probki=1;
	switch(wybor)
	{
		case 1:
			{
				if(iloscdni<=400)
				{
					for(int i=0; i<iloscdni; i++)
					{
						getline(plik1,bufor,',');
						plik1>>open;
						tabdane[0][i]=open;
						getline(plik1,bufor,',');
						plik1>>high;
						tabdane[1][i]=high;
						if(bufhigh<high)
						{
							bufhigh=high;
						}
						getline(plik1,bufor,',');
						plik1>>low;
						tabdane[2][i]=low;
						if(buflow>low)
						{
							buflow=low;
						}
						getline(plik1,bufor,',');
						plik1>>close;
						tabdane[3][i]=close;
						getline(plik1,bufor); //przejscie do nastepnej linijki
					}	
				}
				else
				{
					probki=(iloscdni/400)+1;
					for(int i=0; i<(iloscdni/probki); i++)
					{
						double open1=0, high1=0, low1=0, close1=0;
						for(int j=0; j<probki; j++)
						{
							getline(plik1,bufor,',');
							plik1>>open;
							open1=open1+open;
							getline(plik1,bufor,',');
							plik1>>high;
							high1=high1+high;
							getline(plik1,bufor,',');
							plik1>>low;
							low1=low1+low;
							getline(plik1,bufor,',');
							plik1>>close;
							close1=close1+close;
							getline(plik1,bufor);
						}
						tabdane[0][i]=open1/probki;
						tabdane[1][i]=high1/probki;
						tabdane[2][i]=low1/probki;
						tabdane[3][i]=close1/probki;
						if(bufhigh<high1/probki)
						{
							bufhigh=high1/probki;
						}
						if(buflow>low1/probki)
						{
							buflow=low1/probki;
						}
					}
				}
			}
			break;
			
		case 2:
			{
				int dni;
				cout<<"Co ile dni wykreslac?"<<endl;
				cin>>dni;
				for(int i=0; i<iloscdni/dni; i++)
					{
						double open1=0, high1=0, low1=0, close1=0;
						for(int j=0; j<dni; j++)
						{
							getline(plik1,bufor,',');
							plik1>>open;
							open1=open1+open;
							getline(plik1,bufor,',');
							plik1>>high;
							high1=high1+high;
							getline(plik1,bufor,',');
							plik1>>low;
							low1=low1+low;
							getline(plik1,bufor,',');
							plik1>>close;
							close1=close1+close;
							getline(plik1,bufor);
						}
						tabdane[0][i]=open1/dni;
						tabdane[1][i]=high1/dni;
						tabdane[2][i]=low1/dni;
						tabdane[3][i]=close1/dni;
						if(bufhigh<high1/dni)
						{
							bufhigh=high1/dni;
						}
						if(buflow>low1/dni)
						{
							buflow=low1/dni;
						}
					}
			}
	}
	

	plik1.close();
}
void wczytanieNTDOY(double tabdane[][400], double &buflow, double &bufhigh)
{
	int iloscdni;
	string danedata;
	string datastart;
	string bufor;
	double open, high, low, close;
	cout<<"Wprowadz date(rok-miesiac-dzien) od ktorej ma sie wyswietlac wykres."<<endl;
	cin>>datastart;
	cout<<"Podaj ilosc dni od wyznaczonej daty, ktore chcesz wczytac: ";
	cin>>iloscdni;
	cout<<endl;
	ifstream plik1 ("NTDOY.txt");
	

    if(!plik1)
    {
        cout << "Plik nie otwarty!" << endl;
        exit (1);
    }
    getline(plik1,danedata,',');
	while(datastart!=danedata)
	{
		getline(plik1,bufor);
   		getline(plik1,danedata,',');
   	}
	int wybor;
	cout<<"Wybierz sposob wyswietlania wykresu:"<<endl;
	cout<<"1.Dzien po dniu-zgodnie z plikiem"<<endl<<"2.Manualnie np. co trzy dni, co tydzien"<<endl;
	cin>>wybor;
	int probki=1;
	switch(wybor)
	{
		case 1:
			{
				if(iloscdni<=400)
				{
					for(int i=0; i<iloscdni; i++)
					{
						getline(plik1,bufor,',');
						plik1>>open;
						tabdane[0][i]=open;
						getline(plik1,bufor,',');
						plik1>>high;
						tabdane[1][i]=high;
						if(high>bufhigh)
						{
							bufhigh=high;
						}
						getline(plik1,bufor,',');
						plik1>>low;
						tabdane[2][i]=low;
						if(low<buflow)
						{
							buflow=low;
						}
						getline(plik1,bufor,',');
						plik1>>close;
						tabdane[3][i]=close;
						getline(plik1,bufor); //przejscie do nastepnej linijki
					}	
				}
				else
				{
					probki=(iloscdni/400)+1;
					for(int i=0; i<(iloscdni/probki)+(400-(iloscdni/probki)); i++)
					{
						double open1=0, high1=0, low1=0, close1=0;
						for(int j=0; j<probki; j++)
						{
							getline(plik1,bufor,',');
							plik1>>open;
							open1=open1+open;
							getline(plik1,bufor,',');
							plik1>>high;
							high1=high1+high;
							getline(plik1,bufor,',');
							plik1>>low;
							low1=low1+low;
							getline(plik1,bufor,',');
							plik1>>close;
							close1=close1+close;
							getline(plik1,bufor);
						}
						tabdane[0][i]=open1/probki;
						tabdane[1][i]=high1/probki;
						tabdane[2][i]=low1/probki;
						tabdane[3][i]=close1/probki;
						if(bufhigh<high1/probki)
						{
							bufhigh=high1/probki;
						}
						if(buflow>low1/probki)
						{
							buflow=low1/probki;
						}
					}
				}
			}
			break;
			
		case 2:
			{
				int dni;
				cout<<"Co ile dni wykreslac?"<<endl;
				cin>>dni;
				for(int i=0; i<iloscdni/dni; i++)
					{
						double open1=0, high1=0, low1=0, close1=0;
						for(int j=0; j<dni; j++)
						{
							getline(plik1,bufor,',');
							plik1>>open;
							open1=open1+open;
							getline(plik1,bufor,',');
							plik1>>high;
							high1=high1+high;
							getline(plik1,bufor,',');
							plik1>>low;
							low1=low1+low;
							getline(plik1,bufor,',');
							plik1>>close;
							close1=close1+close;
							getline(plik1,bufor);
						}
						tabdane[0][i]=open1/dni;
						tabdane[1][i]=high1/dni;
						tabdane[2][i]=low1/dni;
						tabdane[3][i]=close1/dni;
						if(bufhigh<high1/dni)
						{
							bufhigh=high1/dni;
						}
						if(buflow>low1/dni)
						{
							buflow=low1/dni;
						}
					}
			}
	}
	

	plik1.close();
}
void rysuj(double tabdane[][400], double &buflow, double &bufhigh, char tabrysuj[][400])
{
	double buflinia;
	double wysokosc;
	
	wysokosc=(bufhigh-buflow)/100;
	for(int j=0; j<400; j++)
	{
		buflinia=buflow;
		for(int i=0; i<100; i++)
		{
			if((tabdane[2][j]<=buflinia)&&(tabdane[1][j]>=buflinia))
			{
				tabrysuj[i][j]='|';
			}
			buflinia=buflinia+wysokosc;
		}
		buflinia=buflow;
		if(tabdane[0][j]>=tabdane[3][j])
		{
			for(int i=0; i<100; i++)
			{
				if((tabdane[0][j]>=buflinia)&&(tabdane[3][j]<=buflinia))
				{
					tabrysuj[i][j]='X';
				}
				buflinia=buflinia+wysokosc;
			}
		}
		else
		{
			for(int i=0; i<100; i++)
			{
				if((tabdane[0][j]<=buflinia)&&(tabdane[3][j]>=buflinia))
				{
					tabrysuj[i][j]='O';
				}
				buflinia=buflinia+wysokosc;
			}
		}
	}
	
}
void utworzplik(char tabrysuj[][400])
{
	ofstream plik1 ("Wykres.txt");
	
	 for(int i=99; i>=0; i--)
	{
		for(int j=0; j<400; j++)
		{
			plik1<<tabrysuj[i][j];
		}
		plik1<<endl;
	}
	plik1.close();
	cout<<"Plik z wykresem zostal utworzony!"<<endl;
}

int main()
{
	char tabrysuj[100][400];
	for(int i=0; i<100; i++)
	{
		for(int j=0; j<400; j++)
		{
			tabrysuj[i][j]=' ';
		}
	}
	double tabdane[4][400];
	double buflow=99999999999, bufhigh=0;
	int ktory;
	cout<<"-----------------------MENU-----------------------"<<endl;
	cout<<"Podaj, ktory plik z danymi chcesz wczytac: "<<endl<<"1.AAPL "<<"2.INTC "<<"3.MSFT "<<"4.NTDOY "<<"0.Zakoncz program"<<endl;
	cin>>ktory;
	switch(ktory)
	{
		case 1:
			{
				wczytanieAAPL(tabdane, buflow, bufhigh);		
			}break;
			
		case 2:
			{
				wczytanieINTC(tabdane, buflow, bufhigh);	
			}break;
		
		case 3:
			{
				wczytanieMSFT(tabdane, buflow, bufhigh);	
			}break;
			
		case 4:
			{
				wczytanieNTDOY(tabdane, buflow, bufhigh);	
			}break;
			
		case 0:
			{
				exit(1);	
			}break;
			
		default: 
			{
				cout<<"Wprowadz odpowiedni znak!"<<endl;
			}break;
	}
	
	rysuj(tabdane, buflow, bufhigh, tabrysuj);
	
	for(int i=99; i>=0; i--)
	{
		for(int j=0; j<400; j++)
		{
			cout<<tabrysuj[i][j];
		}
		cout<<endl;
	}
	utworzplik(tabrysuj);
}
