#include <vector>
#include "../src/humanPlayer.cpp"
#include "../src/robotPlayer.cpp"
#include <iostream>
#include "../src/exchangeMoney.cpp"


int main(){	
	
	HumanPlayer paolo(1);
	HumanPlayer fazio(2);
	
	Square sandalo("A4","E");
	Square malo("B7","L");
	Square sano("B7","S");
	
	std::cout<<exchangeMoney::buying_price(sano)<<std::endl;
	sano.upgrade();
	std::cout<<exchangeMoney::buying_price(malo)<<std::endl;
	std::cout<<exchangeMoney::buying_price(sandalo)<<std::endl;
	sano.upgrade();
	
	
	
	
	
	paolo.buyout(sandalo);
	fazio.buyout(malo);
	

	paolo.build_house(sandalo);
	
	paolo.build_hotel(malo);		

	
	return 0;

}
