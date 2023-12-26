// operacije nad bitovima // && AND u IF daje true/false // || OR u IF daje true/false
// ~ je Negacija
// & je AND, x&x = x, x&~x = 0, x&0 = 0, & koristi se za maskiranje bitova,
// if x&1(proverava poslednji bit) == 1 broj je neparan, u suprotnom paran
// | je OR, xx = x, x|~x = 1, x|0 = x, x = x|2 pretvara pretposlednji bit u 1
// ^ je XOR, if(a!=b)a^b = 1, x^x = 0, x^~x = 1, ^ koristi se za invertovanje bitova x^1 invertuje poslednji bit,
// x^3 invertuje poslednja dva bita
// << je pomeranje bitova u levo, a<<b pomera bitove a za b mesta u levo i popunjuje ostale sa 0
// << se koristi za binarno stepenovanje 
// >> je pomeranje bitova u desno gde ako je UNSIGNED popunjava nulama levo, ako nije unsigned 
// popunjava sa nulama ako je pozitivan a ako je negativan onda popunjava jedinicama
#include<stdio.h>

unsigned x;
int n;

main(){
	scanf("%u%d", &x, &n); 
	x = x&~(~0<<n) 	  // pamtimo samo desne bitove
				     //cuvamo sva mesta u levo tako sto prvo napravimo ~0<<n i dobijemo levo 1 desno 0
				    // zatim ~ opet negiramo da pretvorimo desne nule u jedinice
				   // pa x& da maskiramo tj zapamtimo bitne
	x = x&~(unsigned(~0)>>n) // pamtimo samo leve bitove
							// koristimo unsigned cast da bi garantovali da nece biti neg broj jer radimo sa >>
						   // >>n da bi pamtili brojeve desno
						  // ostalo je isto
	
	
}
