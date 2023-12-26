// egipatksi razlomak govno od logike
// gramzivi algoritam
#include<stdio.h>

int br, im; // brojilac je onaj gore a imenilac onaj dole

void Egipat(int br, int im){ // slucaj kad su deljivi imenilac i brojilac
	if(br%im == 0){
		printf("%d ", br/im);
		return;
	}
	if(im%br == 0){ // slucajevi kad su deljivi br i im ali je imenilac veci pa pisemo inverzno tj pisemo 1/(im/br)
		printf("1/%d", im/br);
		return;
	}
	if(br>im){ // ako je br veci od im podelimo tako da ostane ceo broj i ostatak postaje razlomak 
		printf("%d + ", br/im);
		Egipat(br%im, im); // br je ostatak deljenja br/im a im ostaje isti npr 6/4 je 4/4 + 2/4
		return;
	}
	int im2 = im/br +1; // im2 je novi imenilac koji povecavamo za 1 da bi imali garantovani razlomak
	printf("1/%d + ", im2); // ispisujemo 1/im2 tj novi razlomak npr za 2/3 prelazimo na 3/2 + 1 sto je 1+1=2 i onda imamo 1/2
	Egipat(br*im2-im, im*im2);// ovom formulom teoretski dobijamo br ali posto radimo sa celim brojevima dobicemo 1, i im ce se povecati
}

main(){
	scanf("%d%d", &br, &im);
	Egipat(br,im);
}
