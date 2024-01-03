#include <vector>
#include "../src/humanPlayer.cpp"
#include <iostream>
#include "../src/exchangeMoney.cpp"


int main(){	
	
	humanPlayer paolo;
	humanPlayer fazio;
	
	Square square("E");
	paolo.buyout(square);
	exchangeMoney::pay_someone(paolo,fazio,square);

	
	std::cout<<paolo.getSavings()<<std::endl;
	std::cout<<fazio.getSavings()<<std::endl;
	std::cout<<paolo.dice_throw()<<std::endl;
	std::vector<Square> edifici=paolo.getBuildings();
	std::cout<<edifici[0].get_content()<<std::endl;
	
	return 0;

}
