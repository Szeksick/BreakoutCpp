//---------------------------------------------------------------------------
/* Autorzy:
Konrad Guga³a  Dawid Kowalski
Kamil Zieliñski  Karol Miko³ajczyk

IDE Borland C++ Builder 6

Grafiki z darmowcyh stocków, pexels.com, pixabay.com, unsplash.com,flaticon.com

*/

#pragma hdrstop
#include <cstdio>
#include "fstream.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x=-8, y=-8, x2=-8, y2=-8, pkt=0;;
int win=33;
/*
int kolizja(TImage *pilka, TImage *cegla){
if(pilka->Left+pilka->Width == cegla->Left || pilka->Left == cegla->Left+cegla->Width ){
return 1;
}else if(pilka->Top+pilka->Height == cegla->Top || pilka->Top == cegla->Top+cegla->Height){
return 2;
}else
return 0;
}
void kolizja_blok(TImage *pilka, TImage *blok, int &g, int &u)
{
if((kolizja(pilka,blok)) == 1 && blok->Visible==true){
g=-g; win--; blok->Visible=false;       //od lewej lub prawej
}else if((kolizja(pilka,blok)) == 2 && blok->Visible==true){
u=-u; win--; blok->Visible=false;  //od gory lub od dolu
}
}    */
bool kolizja(TImage *pilka, TImage *cegla)
{
   if( pilka->Left >= cegla->Left-pilka->Width && pilka->Left <= cegla->Left+cegla->Width &&
       pilka->Top >= cegla->Top-pilka->Height && pilka->Top <= cegla->Top+cegla->Height)
      return true;
      else return false;
}
void kolizja_blok(TImage *pilka, TImage *blok, int &g, int &u)
{
        if (kolizja(pilka,blok) && blok->Visible==true)
        {
                if(pilka->Left >= blok->Left-pilka->Width && pilka->Left <= blok->Left+blok->Width)
                        {u=-u; win--; pkt++; blok->Visible=false;}
                 else if(pilka->Top >= blok->Top-pilka->Height && pilka->Top <= blok->Top+blok->Height)
                        {g=-g; win--; pkt++; blok->Visible=false;}
        }
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//-------------------------RUCH PI£KI I KOLIZJE-------------------------------

void __fastcall TForm1::Timer_pilkaTimer(TObject *Sender)
{
        Label4->Caption = pkt;
    b->Left+=x; b->Top+=y;
    if (b->Left-5 <= tlo->Left) x=-x;                           //odbicie b od lewej rawedzi
    if (b->Top-5 <= tlo->Top) y=-y;                             //odbicie b od gornej rawedzi
    if (b->Left+b->Width+5 >= tlo->Width) x=-x;                 //odbicie b od prawej rawedzi
    if (b->Top >= p->Top+p->Height+15 && b2->Visible == false) //b spadla
    {
        Timer_pilka->Enabled = false;
        b->Visible=false;
        Button1->Caption = "Próbuje jeszcze raz";
        Button1->Visible=true;
        wygaszacz->Visible=true;
        Label1->Visible=true;
        Label2->Visible=true;
        Label2->Caption = pkt;
        Label3->Visible=true;
        Nick->Visible = true;
        music->Pause();
        ListBox1->Visible=true;
        Zapisz->Visible=true;
        Label4->Visible=false;
    }
     else if(b->Top >= p->Top+p->Height+15)
    {
       Timer_pilka->Enabled = false;
       b->Visible=false;
    }
    //odbicie b od paletki
    else if(kolizja(b,p))
       {
               if (y>0) y=-y;
       }
    //odbicie b od  b2
    if (kolizja(b,b2)&& b2->Visible==true){
    if(x == x2){
    y2=-y2; y=-y;
    } else {
    x=-x; x2=-x2;
    }
    }
    //wygral
    if  (win<=0){
     win=33;
     Image1->Visible=true; Image5->Visible=true; Image9->Visible=true;
     Image2->Visible=true; Image6->Visible=true; Image10->Visible=true;
     Image3->Visible=true; Image7->Visible=true; Image11->Visible=true;
     Image4->Visible=true; Image8->Visible=true; Image12->Visible=true;
     Image13->Visible=true; Image15->Visible=true; Image18->Visible=true;
     Image14->Visible=true; Image16->Visible=true; Image19->Visible=true;
     Balls2->Visible=true;  Image17->Visible=true; Image20->Visible=true;
     Image21->Visible=true; Image23->Visible=true; Image25->Visible=true;
     Image22->Visible=true; Image24->Visible=true; Image26->Visible=true;
     Image27->Visible=true; Image29->Visible=true; Image31->Visible=true;
     Image28->Visible=true; Image30->Visible=true; Image32->Visible=true;
     }
    kolizja_blok(b,Image1,x,y);
    kolizja_blok(b,Image2,x,y);
    kolizja_blok(b,Image3,x,y);
    kolizja_blok(b,Image4,x,y);
    kolizja_blok(b,Image5,x,y);
    kolizja_blok(b,Image6,x,y);
    kolizja_blok(b,Image7,x,y);
    kolizja_blok(b,Image8,x,y);
    kolizja_blok(b,Image9,x,y);
    kolizja_blok(b,Image10,x,y);
    kolizja_blok(b,Image11,x,y);
    kolizja_blok(b,Image12,x,y);
    kolizja_blok(b,Image13,x,y);
    kolizja_blok(b,Image14,x,y);
    kolizja_blok(b,Image15,x,y);
    kolizja_blok(b,Image16,x,y);
    kolizja_blok(b,Image17,x,y);
    kolizja_blok(b,Image18,x,y);
    kolizja_blok(b,Image19,x,y);
    kolizja_blok(b,Image20,x,y);
    kolizja_blok(b,Image21,x,y);
    kolizja_blok(b,Image22,x,y);
    kolizja_blok(b,Image23,x,y);
    kolizja_blok(b,Image24,x,y);
    kolizja_blok(b,Image25,x,y);
    kolizja_blok(b,Image26,x,y);
    kolizja_blok(b,Image27,x,y);
    kolizja_blok(b,Image28,x,y);
    kolizja_blok(b,Image29,x,y);
    kolizja_blok(b,Image30,x,y);
    kolizja_blok(b,Image31,x,y);
    kolizja_blok(b,Image32,x,y);
    if (kolizja(b,Balls2) && Balls2->Visible==true)
    { b2->Left=384; b2->Top=56; x=-x; y=-y; x2=x; y2=-y; win--; Balls2->Visible=false; b2->Visible=true; Timer_pilka2->Enabled=true; }
}
//-------------------------DODATKOWA PILKA------------------------------

void __fastcall TForm1::Timer_pilka2Timer(TObject *Sender)
{
    Label4->Caption = pkt;
    b2->Left+=x2; b2->Top+=y2;
    if (b2->Left-5 <= tlo->Left) x2=-x2;                           //odbicie b od lewej rawedzi
    if (b2->Top-5 <= tlo->Top) y2=-y2;                             //odbicie b od gornej rawedzi
    if (b2->Left+b->Width+5 >= tlo->Width) x2=-x2;                 //odbicie b od prawej rawedzi
    if (b2->Top >= p->Top+p->Height+15 && b->Visible == false) //b spadla
    {
        Timer_pilka2->Enabled = false;
        b2->Visible=false;
        Button1->Caption = "Próbuje jeszcze raz";
        Button1->Visible=true;
        wygaszacz->Visible=true;
        Label1->Visible=true;
        Label2->Visible=true;
        Label2->Caption = pkt;
        Nick->Visible = true;
        music->Pause();
        ListBox1->Visible=true;
        Zapisz->Visible=true;
        Label4->Visible=false;
    }
    else if(b2->Top >= p->Top+p->Height+15)
    {
       Timer_pilka2->Enabled = false;
       b2->Visible=false;
    }
    //odbicie pilki (b2) od paletki (p)
    else if(b2->Left > p->Left-b2->Width/2 && b2->Left < p->Left+p->Width &&
       b2->Top+b2->Height > p->Top)
       {
               if (y2>0) y2=-y2;
       }
    //wygrana
     if (win<=0){
     win=33;
     Image1->Visible=true; Image5->Visible=true; Image9->Visible=true;
     Image2->Visible=true; Image6->Visible=true; Image10->Visible=true;
     Image3->Visible=true; Image7->Visible=true; Image11->Visible=true;
     Image4->Visible=true; Image8->Visible=true; Image12->Visible=true;
     Image13->Visible=true; Image15->Visible=true; Image18->Visible=true;
     Image14->Visible=true; Image16->Visible=true; Image19->Visible=true;
     Balls2->Visible=true;  Image17->Visible=true; Image20->Visible=true;
     Image21->Visible=true; Image23->Visible=true; Image25->Visible=true;
     Image22->Visible=true; Image24->Visible=true; Image26->Visible=true;
     Image27->Visible=true; Image29->Visible=true; Image31->Visible=true;
     Image28->Visible=true; Image30->Visible=true; Image32->Visible=true;
     }

    kolizja_blok(b2,Image1,x2,y2);
    kolizja_blok(b2,Image2,x2,y2);
    kolizja_blok(b2,Image3,x2,y2);
    kolizja_blok(b2,Image4,x2,y2);
    kolizja_blok(b2,Image5,x2,y2);
    kolizja_blok(b2,Image6,x2,y2);
    kolizja_blok(b2,Image7,x2,y2);
    kolizja_blok(b2,Image8,x2,y2);
    kolizja_blok(b2,Image9,x2,y2);
    kolizja_blok(b2,Image10,x2,y2);
    kolizja_blok(b2,Image11,x2,y2);
    kolizja_blok(b2,Image12,x2,y2);
    kolizja_blok(b2,Image13,x2,y2);
    kolizja_blok(b2,Image14,x2,y2);
    kolizja_blok(b2,Image15,x2,y2);
    kolizja_blok(b2,Image16,x2,y2);
    kolizja_blok(b2,Image17,x2,y2);
    kolizja_blok(b2,Image18,x2,y2);
    kolizja_blok(b2,Image19,x2,y2);
    kolizja_blok(b2,Image20,x2,y2);
    kolizja_blok(b2,Image21,x2,y2);
    kolizja_blok(b2,Image22,x2,y2);
    kolizja_blok(b2,Image23,x2,y2);
    kolizja_blok(b2,Image24,x2,y2);
    kolizja_blok(b2,Image25,x2,y2);
    kolizja_blok(b2,Image26,x2,y2);
    kolizja_blok(b2,Image27,x2,y2);
    kolizja_blok(b2,Image28,x2,y2);
    kolizja_blok(b2,Image29,x2,y2);
    kolizja_blok(b2,Image30,x2,y2);
    kolizja_blok(b2,Image31,x2,y2);
    kolizja_blok(b2,Image32,x2,y2);
      if (kolizja(b2,Balls2) && Balls2->Visible==true)
    {
    if (b->Visible == false){
    b->Top = 56;
    b->Left = 384;
    x=x; y=-y; x2=-x; y2=-y;
    win--;
    pkt++;
    Balls2->Visible=false;
    b->Visible=true; Timer_pilka->Enabled=true;

    }
    x=x; y=-y; x2=-x; y2=-y;
    win--;
    pkt++;
    Balls2->Visible=false;

     }
}
//------------------------STEROWANIE PALETK¥---------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key==VK_LEFT) lewo->Enabled=true;
  if(Key==VK_RIGHT) prawo->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key==VK_LEFT) lewo->Enabled=false;
  if(Key==VK_RIGHT) prawo->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::lewoTimer(TObject *Sender)
{
    if (p->Left>10) p->Left-=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::prawoTimer(TObject *Sender)
{
    if (p->Left+p->Width<tlo->Width-10) p->Left+=10;
}
//-----------------------------START GRY--------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
     music->Play();
     b->Left=680; b->Top=200;
     p->Left=320;
     b->Visible=true;
     b2->Visible=false;
     b2->Left=384; b2->Top=56;
     pkt=0;
     x=8;
     y=8;
     x2=8;
     y2=8;
     Timer_pilka->Enabled=true;
     Timer_pilka2->Enabled=false;
     Button1->Visible=false;
     wygaszacz->Visible=false;
     Label1->Visible=false;
     Label2->Visible=false;
     Label3->Visible=false;
     ListBox1->Visible=false;
     Nick->Visible=false;
     Zapisz->Visible=false;
     p->Visible=true;
     win=33;
     Label4->Visible=true;
     Image1->Visible=true; Image5->Visible=true; Image9->Visible=true;
     Image2->Visible=true; Image6->Visible=true; Image10->Visible=true;
     Image3->Visible=true; Image7->Visible=true; Image11->Visible=true;
     Image4->Visible=true; Image8->Visible=true; Image12->Visible=true;
     Image13->Visible=true; Image15->Visible=true; Image18->Visible=true;
     Image14->Visible=true; Image16->Visible=true; Image19->Visible=true;
     Balls2->Visible=true;  Image17->Visible=true; Image20->Visible=true;
     Image21->Visible=true; Image23->Visible=true; Image25->Visible=true;
     Image22->Visible=true; Image24->Visible=true; Image26->Visible=true;
     Image27->Visible=true; Image29->Visible=true; Image31->Visible=true;
     Image28->Visible=true; Image30->Visible=true; Image32->Visible=true;
     }
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
                music->FileName = "muzyka.mp3";
                music->Open();
                ListBox1->Items->LoadFromFile("lista.txt");


}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
                music->Close();
}
//---------------------------------------------------------------------------






void __fastcall TForm1::ZapiszClick(TObject *Sender)
{
        ListBox1->Items->SaveToFile("lista.txt");
        ListBox1->Items->Append(Label2->Caption+"pkt - "+Nick->Text);
        

}
//---------------------------------------------------------------------------










