#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "projekfix.cpp"

using namespace std;

#define MAX 10

int head = 0;
int tail = 0;
int ID1, ID2;
struct pilihMenu
    {
        int subMenu;
        int chsCat;
        int chsFood;
    }go;

struct Pilih
{
  bool ordering, valid = true;
  char pass;
}p;


struct DATA
{
  vector<vector<int> > order; 
  DATA()
  {
    for (size_t i = 0; i < MAX; i++)
    {
      order.resize(0, vector<int>(2, 0));
    }
  } 
} buyer[MAX];

bool isEmpty(){return (tail == 0) ? true : false;};

bool isFull(){return (tail == MAX) ? true : false;};

bool pilih(){
      if (p.pass=='y' || p.pass == 'Y')
      {
        return true;
      } else
      {
        return false;
      }    
}
// Dari sini
int controlID1(){
  
  if (go.chsFood == 1)
    {
      ID1 = 0;
    } if (go.chsFood == 2)
    {
      ID1 = 1;
    } if (go.chsFood == 3)
    {
      ID1 = 2;
    } if (go.chsFood == 4)
    {
      ID1 = 3;
    } 
}

void enQueue(DATA* x)
{
  controlID1();
  if (!isFull())
  {
    
      cout << "ANTRIAN KE-" << tail+1 << "\n\n";
      do
      {
        cout << "Masukkan Pilihan : ";
        cin >> ID2;
        if (ID1 < 5 && ID2 < 10 && menuMakan[ID1][ID2] != "em") 
        {
          p.valid = true;
          x[tail].order.push_back(vector<int>());
          x[tail].order[x[tail].order.size()-1].push_back(ID1);
          x[tail].order[x[tail].order.size()-1].push_back(ID2); 
        } else
        {
          system("CLS");
          cout << "Pilihan tidak valid!\n";
          p.valid = false;
        }
      } while (!p.valid);
    
  }
  tail++;
};

void displayData(DATA* x)
{
  if (!isEmpty())
  {
    for (size_t i = head; i < tail; i++)
    {
      cout << "Antrian ke-" << i+1 << "\n\n";
      for (size_t j = 0; j < x[i].order.size(); j++)
      {
        cout << menuMakan[buyer[i].order[j][0]][buyer[i].order[j][1]];
        spacing(menuMakan[buyer[i].order[j][0]][buyer[i].order[j][1]]); 
        cout << "  ||  Rp. " << hargaMakan[buyer[i].order[j][0]][buyer[i].order[j][1]] << "\n";
      } 
      cout << "\n";
    }
  } else
  {
    cout << "Data kosong!.";
  }
}



void deQueue(DATA* x)
{
  if (!isEmpty())
  {
    copy(x+1, x+MAX, x);
  } else
  {
    cout << "Data penuh!";
  }
  tail--;
}