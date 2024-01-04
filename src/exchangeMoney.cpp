#include "../include/exchangeMoney.h"


 void exchangeMoney::pay_someone(player& owner,player& borrower,const Square& square){
	owner.add_amount(5);
	borrower.remove_amount(5);
}
	
 void exchangeMoney::passing_prize(player& p1){
  p1.add_amount(20);
}	
	
	
	
	
 int exchangeMoney::square_price(const Square& square){
	return 0;
}